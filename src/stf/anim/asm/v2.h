#pragma once
#include <stf/reflection/reflection.h>
#include <stf/basic-types.h>
#include <ucsl/math.h>

namespace stf::anim::animation_state_machine::v2 {
	struct ClipDataAnimationSettings{
		const char* resourceName;
		float start;
		float end;
		float speed;
		unsigned char flags;
		bool loops;
	};

	struct ClipData {
		const char* name;
		ClipDataAnimationSettings animationSettings;
		unsigned short triggerCount;
		short triggerOffset;
		short blendMaskIndex;
		unsigned short childClipIndexCount;
		short childClipIndexOffset;
	};

	struct TransitionDataTransitionInfo {
		unsigned char type;
		unsigned char easingType;
		short targetStateIndex;
		float transitionTime;
	};

	struct TransitionData {
		TransitionDataTransitionInfo transitionInfo;
		short transitionTimeVariableIndex;
	};

	struct StateData {
		const char* name;
		char type;
		bool transitImmediately;
		unsigned char flags;
		char defaultLayerIndex;
		short rootBlendNodeOrClipIndex;
		short maxCycles;
		float speed;
		short speedVariableIndex;
		unsigned short eventCount;
		short eventOffset;
		short transitionArrayIndex;
		TransitionData stateEndTransition;
		unsigned short flagIndexCount;
		short flagIndexOffset;
		float pbaBlendMaskOpacity;
	};

	struct BlendNodeData {
		unsigned char type;
		short blendSpaceIndex;
		short blendFactorVariableIndex;
		float blendFactorTarget;
		unsigned short childNodeArraySize;
		short childNodeArrayOffset;
	};

	struct TransitionArrayData {
		int size;
		int offset;
	};

	struct EventData {
		const char* name;
		TransitionData transition;
	};

	struct LayerData {
		const char* name;
		unsigned short layerId;
		short blendMaskIndex;
	};

	struct BlendMaskData {
		const char* name;
		unsigned short maskBoneCount;
		short maskBoneOffset;
	};

	struct TriggerData {
		unsigned char type;
		float unknown2;
		float unknown3;
		unsigned short triggerTypeIndex;
		short colliderIndex;
		const char* name;
	};

	struct BlendSpaceDataTriangle {
		short nodeIndex0;
		short nodeIndex1;
		short nodeIndex2;
		short unused;
	};

	struct BlendSpaceData {
		short xVariableIndex;
		short yVariableIndex;
		float xMin;
		float xMax;
		float yMin;
		float yMax;
		unsigned short nodeCount;
		unsigned short triangleCount;
		ucsl::math::Vector2* nodes;
		short* clipIndices;
		BlendSpaceDataTriangle* triangles;
	};

	struct AsmData {
		unsigned int magic;
		int version;
		int clipCount;
		ClipData* clips;
		int stateCount;
		StateData* states;
		int blendNodeCount;
		BlendNodeData* blendNodes;
		int eventCount;
		EventData* events;
		int transitionArrayCount;
		TransitionArrayData* transitionArrays;
		int transitionCount;
		TransitionData* transitions;
		TransitionData nullTransition;
		int flagIndexCount;
		short* flagIndices;
		int flagCount;
		const char** flags;
		int variableCount;
		const char** variables;
		int layerCount;
		LayerData* layers;
		int blendMaskCount;
		BlendMaskData* blendMasks;
		int maskBoneCount;
		const char** maskBones;
		int triggerCount;
		TriggerData* triggers;
		int triggerTypeCount;
		const char** triggerTypes;
		int colliderCount;
		const char** colliders;
		short blendTreeRootNodeId;
		int blendSpaceCount;
		BlendSpaceData* blendSpaces;
		int childClipIndexCount;
		short* childClipIndices;
	};

	namespace reflection {
		using namespace simplerfl;
		using namespace stf::reflection;

		namespace impl = stf::anim::animation_state_machine::v2;

		using ClipDataAnimationSettings = structure<impl::ClipDataAnimationSettings, "ClipDataAnimationSettings", void,
			field<const char*, "resourceName">,
			field<float, "start">,
			field<float, "end">,
			field<float, "speed">,
			field<unsigned char, "flags">,
			field<bool, "loops">
		>;

		using ClipData = structure<impl::ClipData, "ClipData", void,
			field<const char*, "name">,
			field<ClipDataAnimationSettings, "animationSettings">,
			field<unsigned short, "triggerCount">,
			field<short, "triggerOffset">,
			field<short, "blendMaskIndex">,
			field<unsigned short, "childClipIndexCount">,
			field<short, "childClipIndexOffset">
		>;

		using TransitionDataTransitionInfo = structure<impl::TransitionDataTransitionInfo, "TransitionDataTransitionInfo", void,
			field<unsigned char, "type">,
			field<unsigned char, "easingType">,
			field<short, "targetStateIndex">,
			field<float, "transitionTime">
		>;

		using TransitionData = structure<impl::TransitionData, "TransitionData", void,
			field<TransitionDataTransitionInfo, "transitionInfo">,
			field<short, "transitionTimeVariableIndex">
		>;

		using StateData = structure<impl::StateData, "StateData", void,
			field<const char*, "name">,
			field<char, "type">,
			field<bool, "transitImmediately">,
			field<unsigned char, "flags">,
			field<char, "defaultLayerIndex">,
			field<short, "rootBlendNodeOrClipIndex">,
			field<short, "maxCycles">,
			field<float, "speed">,
			field<short, "speedVariableIndex">,
			field<unsigned short, "eventCount">,
			field<short, "eventOffset">,
			field<short, "transitionArrayIndex">,
			field<TransitionData, "stateEndTransition">,
			field<unsigned short, "flagIndexCount">,
			field<short, "flagIndexOffset">,
			field<float, "pbaBlendMaskOpacity">
		>;

		using BlendNodeData = structure<impl::BlendNodeData, "BlendNodeData", void,
			field<unsigned char, "type">,
			field<short, "blendSpaceIndex">,
			field<short, "blendFactorVariableIndex">,
			field<float, "blendFactorTarget">,
			field<unsigned short, "childNodeArraySize">,
			field<short, "childNodeArrayOffset">
		>;

		using TransitionArrayData = structure<impl::TransitionArrayData, "TransitionArrayData", void,
			field<int, "size">,
			field<int, "offset">
		>;

		using EventData = structure<impl::EventData, "EventData", void,
			field<const char*, "name">,
			field<TransitionData, "transition">
		>;

		using LayerData = structure<impl::LayerData, "LayerData", void,
			field<const char*, "name">,
			field<unsigned short, "layerId">,
			field<short, "blendMaskIndex">
		>;

		using BlendMaskData = structure<impl::BlendMaskData, "BlendMaskData", void,
			field<const char*, "name">,
			field<unsigned short, "maskBoneCount">,
			field<short, "maskBoneOffset">
		>;

		using TriggerData = structure<impl::TriggerData, "TriggerData", void,
			field<uint8_t, "type">,
			field<float, "unknown2">,
			field<float, "unknown3">,
			field<unsigned short, "triggerTypeIndex">,
			field<short, "colliderIndex">,
			field<const char*, "name">
		>;

		using BlendSpaceDataTriangle = structure<impl::BlendSpaceDataTriangle, "BlendSpaceDataTriangle", void,
			field<short, "nodeIndex0">,
			field<short, "nodeIndex1">,
			field<short, "nodeIndex2">,
			field<short, "unused">
		>;

		using BlendSpaceData = structure<impl::BlendSpaceData, "BlendSpaceData", void,
			field<short, "xVariableIndex">,
			field<short, "yVariableIndex">,
			field<float, "xMin">,
			field<float, "xMax">,
			field<float, "yMin">,
			field<float, "yMax">,
			field<unsigned short, "nodeCount">,
			field<unsigned short, "triangleCount">,
			field<dynamic_carray<ucsl::math::Vector2, impl::BlendSpaceData, [](const impl::BlendSpaceData& parent) -> size_t { return parent.nodeCount; }>*, "nodes">,
			field<dynamic_carray<short, impl::BlendSpaceData, [](const impl::BlendSpaceData& parent) -> size_t { return parent.nodeCount; }>*, "clipIndices">,
			field<dynamic_carray<BlendSpaceDataTriangle, impl::BlendSpaceData, [](const impl::BlendSpaceData& parent) -> size_t { return parent.triangleCount; }>*, "triangles">
		>;

		using AsmData = structure<impl::AsmData, "AsmData", void,
			field<unsigned int, "magic">,
			field<int, "version">,
			field<int, "clipCount">,
			field<dynamic_carray<ClipData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.clipCount; }>*, "clips">,
			field<int, "stateCount">,
			field<dynamic_carray<StateData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.stateCount; }>*, "states">,
			field<int, "blendNodeCount">,
			field<dynamic_carray<BlendNodeData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.blendNodeCount; }>*, "blendNodes">,
			field<int, "eventCount">,
			field<dynamic_carray<EventData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.eventCount; }>*, "events">,
			field<int, "transitionArrayCount">,
			field<dynamic_carray<TransitionArrayData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.transitionArrayCount; }>*, "transitionArrays">,
			field<int, "transitionCount">,
			field<dynamic_carray<TransitionData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.transitionCount; }>*, "transitions">,
			field<TransitionData, "nullTransition">,
			field<int, "flagIndexCount">,
			field<dynamic_carray<short, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.flagIndexCount; }>*, "flagIndices">,
			field<int, "flagCount">,
			field<dynamic_carray<const char*, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.flagCount; }>*, "flags">,
			field<int, "variableCount">,
			field<dynamic_carray<const char*, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.variableCount; }>*, "variables">,
			field<int, "layerCount">,
			field<dynamic_carray<LayerData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.layerCount; }>*, "layers">,
			field<int, "blendMaskCount">,
			field<dynamic_carray<BlendMaskData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.blendMaskCount; }>*, "blendMasks">,
			field<int, "maskBoneCount">,
			field<dynamic_carray<const char*, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.maskBoneCount; }>*, "maskBones">,
			field<int, "triggerCount">,
			field<dynamic_carray<TriggerData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.triggerCount; }>*, "triggers">,
			field<int, "triggerTypeCount">,
			field<dynamic_carray<const char*, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.triggerTypeCount; }>*, "triggerTypes">,
			field<int, "colliderCount">,
			field<dynamic_carray<const char*, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.colliderCount; }>*, "colliders">,
			field<short, "blendTreeRootNodeId">,
			field<int, "blendSpaceCount">,
			field<dynamic_carray<BlendSpaceData, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.blendSpaceCount; }>*, "blendSpaces">,
			field<int, "childClipIndexCount">,
			field<dynamic_carray<short, impl::AsmData, [](const impl::AsmData& parent) -> size_t { return parent.childClipIndexCount; }>*, "childClipIndices">
		>;
	}
}

namespace simplerfl {
	template<> struct canonical<stf::anim::animation_state_machine::v2::ClipDataAnimationSettings> { using type = stf::anim::animation_state_machine::v2::reflection::ClipDataAnimationSettings; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::ClipData> { using type = stf::anim::animation_state_machine::v2::reflection::ClipData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::TransitionDataTransitionInfo> { using type = stf::anim::animation_state_machine::v2::reflection::TransitionDataTransitionInfo; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::TransitionData> { using type = stf::anim::animation_state_machine::v2::reflection::TransitionData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::StateData> { using type = stf::anim::animation_state_machine::v2::reflection::StateData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::BlendNodeData> { using type = stf::anim::animation_state_machine::v2::reflection::BlendNodeData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::TransitionArrayData> { using type = stf::anim::animation_state_machine::v2::reflection::TransitionArrayData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::EventData> { using type = stf::anim::animation_state_machine::v2::reflection::EventData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::LayerData> { using type = stf::anim::animation_state_machine::v2::reflection::LayerData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::BlendMaskData> { using type = stf::anim::animation_state_machine::v2::reflection::BlendMaskData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::TriggerData> { using type = stf::anim::animation_state_machine::v2::reflection::TriggerData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::BlendSpaceDataTriangle> { using type = stf::anim::animation_state_machine::v2::reflection::BlendSpaceDataTriangle; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::BlendSpaceData> { using type = stf::anim::animation_state_machine::v2::reflection::BlendSpaceData; };
	template<> struct canonical<stf::anim::animation_state_machine::v2::AsmData> { using type = stf::anim::animation_state_machine::v2::reflection::AsmData; };
}
