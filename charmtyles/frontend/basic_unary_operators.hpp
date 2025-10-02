#pragma once

#include <charmtyles/util/generator.hpp>
#include <cmath>

namespace ct {

    class negate_op : public ct::unary_operator
    {
    public:
        KOKKOS_FUNCTION negate_op(){};
        KOKKOS_FUNCTION ~negate_op(){};

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return -value;
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return -value;
        }
    };

    class abs_op : public ct::unary_operator
    {
    public:
        abs_op() = default;
        ~abs_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return std::abs(value);
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return std::abs(value);
        }

        
        abs_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class square_op : public ct::unary_operator
    {
    public:
        square_op() = default;
        ~square_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return value * value;
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return value * value;
        }

        
        square_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class sqrt_op : public ct::unary_operator
    {
    public:
        sqrt_op() = default;
        ~sqrt_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return std::sqrt(value);
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return std::sqrt(value);
        }

        
        sqrt_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class reciprocal_op : public ct::unary_operator
    {
    public:
        reciprocal_op() = default;
        ~reciprocal_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return 1.0 / value;
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return 1.0 / value;
        }

        
        reciprocal_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class sin_op : public ct::unary_operator
    {
    public:
        sin_op() = default;
        ~sin_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return std::sin(value);
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return std::sin(value);
        }

        
        sin_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class cos_op : public ct::unary_operator
    {
    public:
        cos_op() = default;
        ~cos_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return std::cos(value);
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return std::cos(value);
        }

        
        cos_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class log_op : public ct::unary_operator
    {
    public:
        log_op() = default;
        ~log_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return std::log(value);
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return std::log(value);
        }

        
        log_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class exp_op : public ct::unary_operator
    {
    public:
        exp_op() = default;
        ~exp_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return std::exp(value);
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return std::exp(value);
        }

        
        exp_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    class scale_op : public ct::unary_operator
    {
    public:
        scale_op() = delete;    // Require scale factor
        scale_op(double scale_factor)
          : scale_factor_(scale_factor)
        {
        }
        ~scale_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return scale_factor_ * value;
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return scale_factor_ * value;
        }

        
        scale_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }

        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
            p | scale_factor_;
        }

    private:
        double scale_factor_;
    };

    class add_constant_op : public ct::unary_operator
    {
    public:
        add_constant_op() = delete;    // Require constant
        add_constant_op(double constant)
          : constant_(constant)
        {
        }
        ~add_constant_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return value + constant_;
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return value + constant_;
        }

        
        add_constant_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }

        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
            p | constant_;
        }

    private:
        double constant_;
    };

    class relu_op : public ct::unary_operator
    {
    public:
        relu_op() = default;
        ~relu_op() = default;

        using ct::unary_operator::unary_operator;

        KOKKOS_FUNCTION virtual double operator()(std::size_t index, double value) 
        {
            return std::max(0.0, value);
        }

        KOKKOS_FUNCTION virtual double operator()(
            std::size_t i, std::size_t j, double value) 
        {
            return std::max(0.0, value);
        }

        
        relu_op(CkMigrateMessage* m)
          : ct::unary_operator(m)
        {
        }
        void pup(PUP::er& p) 
        {
            ct::unary_operator::pup(p);
        }
    };

    template<typename T>
    T* construct_unop_ptr() {
        #ifdef KOKKOS_ENABLE_CUDA
        void* deviceInstanceMemory = Kokkos::kokkos_malloc(sizeof(T));
        Kokkos::parallel_for("initialize", 1, KOKKOS_LAMBDA (const int i) {
            new (static_cast<T*>(deviceInstanceMemory)) T(); // initialize on device
        });
        return static_cast<T*>(deviceInstanceMemory);
        #else
        return new T();
        #endif
        
    }
    
    void deallocate_unop_ptr(ct::unary_operator* ptr){
        #ifdef KOKKOS_ENABLE_CUDA
        Kokkos::parallel_for("destroy", 1, KOKKOS_LAMBDA (const int i) {
            ptr->~unary_operator(); // destroy on device
        });
        Kokkos::kokkos_free(ptr);
        #else
        delete (negate_op*)unop_ptr;
        #endif
        ckout<<"destroyed successfully"<<endl;
    }


    class negate_op_wrapper: public unary_op_wrapper{
        public:
        PUPable_decl(negate_op_wrapper);
        negate_op_wrapper(){
            unop_ptr = construct_unop_ptr<ct::negate_op>();
        };
        
        ~negate_op_wrapper(){
            deallocate_unop_ptr(unop_ptr);
        }
        void pup(PUP::er& p){
            unary_op_wrapper::pup(p);
            if(p.isUnpacking()){
                unop_ptr = construct_unop_ptr<ct::negate_op>();
            }
        }

        negate_op_wrapper(CkMigrateMessage* m)
          : unary_op_wrapper(m)
        {
        }
    };

    namespace unary_ops {
        // template<typename op> 
        // can we make this templatized?
        inline std::shared_ptr<unary_op_wrapper> negate()
        {
            return std::make_shared<negate_op_wrapper>();
        }
        // inline ct::negate_op* negate()
        // {
        //     return new ct::negate_op();
        // }

        inline std::shared_ptr<ct::unary_operator> abs()
        {
            return std::make_shared<abs_op>();
        }

        inline std::shared_ptr<ct::unary_operator> square()
        {
            return std::make_shared<square_op>();
        }

        inline std::shared_ptr<ct::unary_operator> sqrt()
        {
            return std::make_shared<sqrt_op>();
        }

        inline std::shared_ptr<ct::unary_operator> reciprocal()
        {
            return std::make_shared<reciprocal_op>();
        }

        inline std::shared_ptr<ct::unary_operator> sin()
        {
            return std::make_shared<sin_op>();
        }

        inline std::shared_ptr<ct::unary_operator> cos()
        {
            return std::make_shared<cos_op>();
        }

        inline std::shared_ptr<ct::unary_operator> log()
        {
            return std::make_shared<log_op>();
        }

        inline std::shared_ptr<ct::unary_operator> exp()
        {
            return std::make_shared<exp_op>();
        }

        inline std::shared_ptr<ct::unary_operator> scale(double factor)
        {
            return std::make_shared<scale_op>(factor);
        }

        inline std::shared_ptr<ct::unary_operator> add_constant(double constant)
        {
            return std::make_shared<add_constant_op>(constant);
        }

        inline std::shared_ptr<ct::unary_operator> relu()
        {
            return std::make_shared<relu_op>();
        }
    }    // namespace unary_ops

}    // namespace ct
