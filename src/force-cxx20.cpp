#include <simple-reflection/declarations.h>
//#include <he2-reflection/types.h>
#include <iostream>

using namespace simplerfl::declarations;

using Bar = structure<"Bar", void,
	field<unsigned long long, "c">
>;

using Foo = structure<"Foo", void,
	field<int, "a">,
	field<float, "b">,
	field<Bar, "bar">
>;

using Rep = representation_t<Foo>;

struct Bar2 {
	unsigned long long c;
};

struct Foo2 {
	int a;
	float b;
	Bar2 bar;
};

extern size_t x = 0;

struct test_alg {
	using result_type = size_t;
	static constexpr size_t arity = 1;

	std::string depth{};

	template<typename T>
	size_t visit_primitive(T* t) {
		std::cout << depth << "Value: " << *t << std::endl;
		return x += 1;
	}
	template<>
	size_t visit_primitive(int* t) {
		std::cout << depth << "Value: " << *t << std::endl;
		return x += *t;
	}

	size_t visit_array(void* obj) {

	}

	size_t visit_enum(void* obj) {

	}

	size_t visit_flags(void* obj) {

	}

	size_t visit_pointer(void* obj) {

	}

	size_t visit_array_field(void* obj) {

	}

	template<typename F>
	size_t visit_field(void* obj, const std::string& name, size_t alignment, F f) {
		std::cout << depth << "Field: " << name << std::endl;
		return f(obj);
	}

	template<typename F>
	size_t visit_base_struct(void* obj, const std::string& name, F f) {
		return f(obj);
	}

	template<typename F>
	size_t visit_struct(void* obj, const std::string& name, F f) {
		std::cout << depth << "Struct: " << name << std::endl;
		depth += "  ";
		size_t result = f(obj);
		depth = depth.substr(0, depth.size() - 2);
		return result;
	}
};

using Test = reflection::traversal<test_alg>;

int main() {
	Foo2 foo{ 45, 21.0f, { 2939 } };
	Test::apply<Foo>(&foo);
}
