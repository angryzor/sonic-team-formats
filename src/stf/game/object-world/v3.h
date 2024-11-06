#pragma once
#include <stf/reflection/reflection.h>
#include <stf/basic-types.h>
#include <ucsl/ut/array.h>

namespace stf::game::object_world::v3 {
    using namespace simplerfl;
    using namespace stf::reflection;

    using ObjectTransformData = structure<"ObjectTransformData", void,
        field<csl::math::Position, "position">,
        field<csl::math::Position, "rotation">
    >;

    using ComponentData = structure<"ComponentData", void,
        field<erased<unsigned long long>, "unk1">,
        field<const char*, "type">,
        field<unsigned long long, "size">,
        field<componentdata_rflclass<ComponentData, [](auto& parent) -> const char* { return parent.type; }>*, "data">
    >;

    using ObjectData = structure<"ObjectData", void,
        field<erased<unsigned int>, "flags">,
        field<const char*, "gameObjectClass">,
        field<csl::ut::VariableString, "name">,
        field<hh::game::ObjectIdV2, "id">,
        field<hh::game::ObjectIdV2, "parentID">,
        field<ObjectTransformData, "transform">,
        field<ObjectTransformData, "localTransform">,
        field<ucsl::ut::arrays::Array<ComponentData>, "componentData">,
        field<rflclass<ObjectData, [](auto& parent) -> const char* { return parent.gameObjectClass; }>*, "spawnerData">
    >;

    using ObjectWorldData = structure<"ObjectWorldData", void,
        field<erased<unsigned int>, "unk1">,
        field<erased<unsigned int>, "unk2">,
        field<erased<unsigned char>, "flags">,
        field<ucsl::ut::arrays::Array<ObjectData*>, "objects">
    >;
}
