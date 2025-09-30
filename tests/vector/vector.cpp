#include <charmtyles/charmtyles.hpp>
#include <charmtyles/frontend/basic_unary_operators.hpp>
#include <charmtyles/frontend/basic_binary_operators.hpp>

#include <vector>
#include <type_traits>

#include "base.decl.h"

#include <Kokkos_Core.hpp>

// class Base {
//   public:
//   void Foo() {}

//   KOKKOS_FUNCTION
//   virtual void Bar() {}
// };

// class Derived : public Base {
//   public:
//   KOKKOS_FUNCTION
//   void Bar() override {}
// };

class Main : public CBase_Main
{
public:
    Main(CkArgMsg* msg)
    {
        int num_pes = 6;
        if (msg->argc > 1)
            num_pes = atoi(msg->argv[1]);

        ct::init();
        thisProxy.check_kokkos();
    }

    
    // class small_func{
    //     using view_t = Kokkos::View<double*>;
    //     view_t x;
    //     view_t y;
    //     small_func(view_t _x, view_t _y): x(_x), y(_y);

    //     KOKKOS_INLINE_FUNCTION int f(int i){
            
    //     }
    // };
    KOKKOS_INLINE_FUNCTION int f(int n){
        return 1;
    }
    
    void check_kokkos(){
        // Kokkos::vector<Kokkos::View<double*>> ;
        // Kokkos::View<double[5]> a("a");
        // Kokkos::View<double[5]> b("b");
        // Kokkos::View<double[5]> res("b");
        // Kokkos::deep_copy(a,2.0);
        // Kokkos::deep_copy(b,1.0);
        // Kokkos::parallel_for("test", 5, KOKKOS_LAMBDA(int i) {
        //     res(i) = f(a(i)+b(i));
        // });
        // auto host_vector = Kokkos::create_mirror_view(res);
        // Kokkos::deep_copy(host_vector, res);
        // for(int i=0;i<5;i++){
        //     ckout<<host_vector(i)<<endl;
        // }
        // using mem_t  = typename Kokkos::View<double*>::memory_space;
        // ckout<<"mem_id "<<typeid(mem_t).name()<<endl;

        // void* deviceInstanceMemory = Kokkos::kokkos_malloc(sizeof(Derived)); // allocate memory on device
        // Kokkos::parallel_for("initialize", 1, KOKKOS_LAMBDA (const int i) {
        //     new (static_cast<Derived*>(deviceInstanceMemory)) Derived(); // initialize on device
        // });
        // Base* deviceInstance = static_cast<Derived*>(deviceInstanceMemory); // declare on this memory

        // // use
        // Kokkos::parallel_for("myKernel", 10, KOKKOS_LAMBDA (const int i) {
        //     deviceInstance->Bar();
        // });
        // ckout<<"destroyed"<<endl;

        // // cleanup
        // Kokkos::parallel_for("destroy", 1, KOKKOS_LAMBDA (const int i) {
        //     deviceInstance->~Base(); // destroy on device
        // });
        // Kokkos::kokkos_free(deviceInstanceMemory); // free
        thisProxy.benchmark();
    }

    void benchmark()
    {
        constexpr std::size_t vec_size_1 = 1<<26;
        constexpr std::size_t vec_size_2 = 1<<26;
        constexpr std::size_t vec_size_3 = 1<<26;

        double start = CkWallTimer();

        ct::vector vec1{vec_size_1, .5};
        ct::vector vec2{vec_size_1, 1.5};
        ct::vector vec3{vec_size_1, .5};

        // ckout<<std::is_trivially_destructible<ct::max_op>::value<<endl;
        ct::vector neg_result = ct::unary_expr(vec1, ct::unary_ops::negate());
        auto unop_wrapper = ct::unary_ops::negate();
        // // auto unop_wrapper = ct::unary_ops::negate();
        Kokkos::View<double[5]> a("a");
        Kokkos::View<double[5]> b("b");
        Kokkos::View<double[5]> res("res");
        Kokkos::deep_copy(a,2.0);
        Kokkos::deep_copy(b,1.0);
        // ckout<<unary_op<<endl;
        // ckout<<unary_op->test_val<<endl;
        ct::unary_operator* op = unop_wrapper->unop_ptr;
        Kokkos::parallel_for("test", 5, KOKKOS_LAMBDA(int i) {
            // if(i==0){
                // Kokkos::printf("at device val,  %d\n", op->test_val);
                // ckout<<unop_wrapper->unop_ptr->test_val<<endl;
            // }
            // res(i) = unop_wrapper->unop_ptr->operator()(i, a(i)+b(i));
            res(i) = op->operator()(i, a(i)+b(i));
        });

        auto host_vector = Kokkos::create_mirror_view(res);
        Kokkos::deep_copy(host_vector, res);
        for(int i=0;i<5;i++){
            ckout<<host_vector(i)<<endl;
        }
        
        ct::vector vec4 = neg_result*vec2-vec3;

        // ct::vector vec11{vec_size_2};
        // ct::vector vec12{vec_size_2, 1.5};
        // ct::vector vec13{vec_size_2, .5};

        // ct::vector vec14 = vec11 + vec12 - vec13;

        // ct::vector vec111{vec_size_3};
        // ct::vector vec112{vec_size_3, 1.5};
        // ct::vector vec113{vec_size_3, .5};

        // ct::vector vec114 = vec111 + vec112 - vec113;

        // ct::vec_impl::vec_instr_queue_t& queue =
        //     CT_ACCESS_SINGLETON(ct::vec_impl::vec_instr_queue);
        // queue.print_instructions();

        ct::sync();

        // double end = CkWallTimer();

        // ckout << "Execution Time (Phase 1): " << end - start << endl;

        // start = CkWallTimer();
        // vec4 = vec1 - vec3 + vec4;
        // vec14 = vec11 - vec13 + vec14;
        // vec114 = vec111 - vec113 + vec114;

        // // in-place operation
        // ct::vector vec115 = vec112 -= vec113;
        // vec115 += vec111 += vec112;

        // ct::sync();
        // end = CkWallTimer();

        // ckout << "Execution Time (Phase 2): " << end - start << endl;

        // // copy operator
        // vec4 = vec1;
        // // copy constructor
        // ct::vector vec5 = vec4;

        // ct::sync();

        std::vector<double> vec4_get = vec4.get();
        for(int i=0;i<5;i++){
            ckout<<vec4_get[i]<<" ";
        }
        ckout<<endl;
        for(int i=0;i<5;i++){
            ckout<<vec4_get[1<<20 + i]<<" ";
        }
        ckout<<endl;
        for(int i=0;i<5;i++){
            ckout<<vec4_get[2*1<<20 + i]<<" ";
        }
        ckout<<endl;

        // ct::vector x{1 << 21, 1.0};
        // ct::vector y{1 << 21, 2.0};
        // ct::scalar scal1 = ct::dot(x, y);
        // double underlying_val = scal1.get();

        // ckout << "Result of Vector dot product: " << underlying_val << endl;

        // Test our new from_vector functionality
        // std::vector<double> test_data = {1.1, 2.2, 3.3, 4.4, 5.5};
        // ct::vector custom_vec = ct::from_vector(test_data);
        // ct::sync();
        
        // std::vector<double> result = custom_vec.get();
        // ckout << "Custom vector elements: ";
        // for (const auto& val : result) {
        //     ckout << val << " ";
        // }
        // ckout << endl;

        ct::finalize();
        CkExit();
    }
};

#include "base.def.h"