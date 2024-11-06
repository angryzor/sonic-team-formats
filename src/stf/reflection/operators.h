#pragma once

namespace stf::reflection {
    template<typename Type> struct erased {
        using type = simplerfl::resolve_decl_t<Type>;
    };

    template<typename Type> struct is_erased {
        static constexpr bool value = is_erased<Type::type>::value;
    };
    template<typename T> struct is_erased<simplerfl::primitive<T>> {
        static constexpr bool value = false;
    };
    template<typename Type> struct is_erased<erased<Type>> {
        static constexpr bool value = true;
    };
    template<typename Type> static constexpr bool is_erased_v = is_erased<Type>::value;

    template<typename Parent> using rflclass_resolver = const char* (*)(const Parent& parent);
    template<typename Parent, rflclass_resolver<Parent> resolver> struct rflclass {
        static constexpr rflclass_resolver<Parent> resolver = resolver;
    };

    template<typename Parent> using componentdata_resolver = const char* (*)(const Parent& parent);
    template<typename Parent, componentdata_resolver<Parent> resolver> struct componentdata_rflclass {
        static constexpr rflclass_resolver<Parent> resolver = resolver;
    };
}

namespace simplerfl {
    template<typename Type> struct desugar<stf::reflection::erased<Type>> { using type = typename desugar<typename stf::reflection::erased<Type>::type>::type; };
}
