#pragma once
#include <stf/reflection/reflection.h>
#include <ucsl/memory/iallocator.h>
#include <ucsl/containers/arrays/array.h>
#include <ucsl/containers/arrays/tarray.h>
#include <ucsl/strings/variable-string.h>
#include <ucsl/math.h>
#include <ucsl/colors.h>
#include <ucsl/object-id.h>

namespace stf::reflection {
	using namespace simplerfl;

	using Vector2 = structure<ucsl::math::Vector2, "Vector2", void,
		field<float, "x">,
		field<float, "y">
	>;

	using Vector3 = aligned<16, structure<ucsl::math::Vector3, "Vector3", void,
		field<float, "x">,
		field<float, "y">,
		field<float, "z">
	>>;

	using Vector4 = aligned<16, structure<ucsl::math::Vector4, "Vector4", void,
		field<float, "x">,
		field<float, "y">,
		field<float, "z">,
		field<float, "w">
	>>;

	using Quaternion = aligned<16, structure<ucsl::math::Quaternion, "Quaternion", void,
		field<float, "x">,
		field<float, "y">,
		field<float, "z">,
		field<float, "w">
	>>;

	using Matrix34 = aligned<16, structure<ucsl::math::Matrix34, "Matrix34", void,
		field<Vector4, "t">,
		field<Vector4, "u">,
		field<Vector4, "v">,
		field<Vector4, "w">
	>>;

	using Matrix44 = aligned<16, structure<ucsl::math::Matrix44, "Matrix44", void,
		field<Vector4, "t">,
		field<Vector4, "u">,
		field<Vector4, "v">,
		field<Vector4, "w">
	>>;

	using Position = structure<ucsl::math::Position, "Position", void,
		field<float, "x">,
		field<float, "y">,
		field<float, "z">
	>;

	using Rotation = structure<ucsl::math::Rotation, "Rotation", void,
		field<float, "x">,
		field<float, "y">,
		field<float, "z">
	>;

	template<typename T> size_t get_array_size(const ucsl::containers::arrays::Array<T>& arr) { return arr.size(); }
	template<typename T>
	using Array = structure<ucsl::containers::arrays::Array<T>, "Array", void,
		field<dynamic_carray<T, ucsl::containers::arrays::Array<T>, get_array_size<T>>*, "buffer">,
		field<size_t, "length">,
		field<size_t, "capacity">,
		field<erased<ucsl::memory::IAllocator*>, "allocator">
	>;

	template<typename T, ucsl::containers::arrays::AllocatorGetterFn* get_allocator> size_t get_tarray_size(const ucsl::containers::arrays::TArray<T, get_allocator>& arr) { return arr.size(); }
	template<typename T, ucsl::containers::arrays::AllocatorGetterFn* get_allocator>
	using TArray = structure<ucsl::containers::arrays::TArray<T, get_allocator>, "TArray", void,
		field<dynamic_carray<T, ucsl::containers::arrays::TArray<T, get_allocator>, get_tarray_size<T, get_allocator>>*, "buffer">,
		field<size_t, "length">,
		field<size_t, "capacity">
	>;

	using VariableString = structure<ucsl::strings::VariableString, "VariableString", void,
		field<const char*, "buffer">,
		field<erased<ucsl::memory::IAllocator*>, "allocator">
	>;

	using ObjectIdV1 = primitive<ucsl::objectids::ObjectIdV1>;

	using ObjectIdV2 = structure<ucsl::objectids::ObjectIdV2, "ObjectId", void,
		field<unsigned long long, "groupId">,
		field<unsigned long long, "objectId">
	>;
}

namespace simplerfl {
	template<> struct canonical<ucsl::memory::IAllocator*> { using type = primitive<size_t>; };
	template<> struct canonical<ucsl::math::Vector2> { using type = stf::reflection::Vector2; };
	template<> struct canonical<ucsl::math::Vector3> { using type = stf::reflection::Vector3; };
	template<> struct canonical<ucsl::math::Vector4> { using type = stf::reflection::Vector4; };
	template<> struct canonical<ucsl::math::Quaternion> { using type = stf::reflection::Quaternion; };
	template<> struct canonical<ucsl::math::Matrix34> { using type = stf::reflection::Matrix34; };
	template<> struct canonical<ucsl::math::Matrix44> { using type = stf::reflection::Matrix44; };
	template<> struct canonical<ucsl::math::Position> { using type = stf::reflection::Position; };
	template<> struct canonical<ucsl::math::Rotation> { using type = stf::reflection::Rotation; };
	template<typename T> struct canonical<ucsl::containers::arrays::Array<T>> { using type = stf::reflection::Array<T>; };
	template<typename T, ucsl::containers::arrays::AllocatorGetterFn* get_allocator> struct canonical<ucsl::containers::arrays::TArray<T, get_allocator>> { using type = stf::reflection::TArray<T, get_allocator>; };
	template<> struct canonical<ucsl::strings::VariableString> { using type = stf::reflection::VariableString; };
	template<> struct canonical<ucsl::objectids::ObjectIdV1> { using type = stf::reflection::ObjectIdV1; };
	template<> struct canonical<ucsl::objectids::ObjectIdV2> { using type = stf::reflection::ObjectIdV2; };
}
