#include <charmtyles/charmtyles.hpp>
#include <charmtyles/frontend/basic_unary_operators.hpp>

#include <vector>
#include <type_traits>

#include <Kokkos_Core.hpp>
#include "base.decl.h"

class identity_t : public ct::unary_operator
{
public:
    KOKKOS_FUNCTION identity_t() {};
    KOKKOS_FUNCTION ~identity_t() {}

    using ct::unary_operator::unary_operator;

    KOKKOS_FUNCTION double operator()(std::size_t index, double value)
    {
        return 1.0;
    }

    KOKKOS_FUNCTION double operator()(
        std::size_t rows, std::size_t cols, double value) 
    {
        if (rows == cols)
        {
            return 1.0;
        }
        else
        {
            return 0.;
        }
    }
};

class identity_op_wrapper: public ct::unary_op_wrapper{
    public:
    PUPable_decl(identity_op_wrapper);
    identity_op_wrapper(){
        unop_ptr = ct::construct_unop_ptr<identity_t>();
    };
    
    ~identity_op_wrapper(){
        ct::deallocate_unop_ptr(unop_ptr);
    }
    void pup(PUP::er& p){
        ct::unary_op_wrapper::pup(p);
        if(p.isUnpacking()){
            unop_ptr = ct::construct_unop_ptr<identity_t>();
        }
    }

    identity_op_wrapper(CkMigrateMessage* m)
      : ct::unary_op_wrapper(m)
    {
    }
};

class Main : public CBase_Main
{
public:
    Main(CkArgMsg* msg)
    {
        int num_pes = 6;
        if (msg->argc > 1)
            num_pes = atoi(msg->argv[1]);

        ct::init();
        thisProxy.benchmark();
    }

    void benchmark()
    {
        std::shared_ptr<ct::unary_op_wrapper> identity =
            std::make_shared<identity_op_wrapper>();
        ct::vector v1{1000, 1.0};
        
        ct::vector cpy = ct::unary_expr(v1, identity);
        auto cpy_val = cpy.get();
        for(int i=0;i<100;i++){
            ckout<<cpy_val[i]<<" ";
        }
        ckout<<endl;
        ct::finalize();
        CkExit();
    }
};

#include "base.def.h"
