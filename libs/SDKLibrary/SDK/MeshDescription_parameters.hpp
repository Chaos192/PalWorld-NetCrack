#pragma once

// Dumped with Dumper-7!


#include "../SDK.hpp"

namespace SDK
{
namespace Params
{
//---------------------------------------------------------------------------------------------------------------------
// PARAMETERS
//---------------------------------------------------------------------------------------------------------------------

// 0x20 (0x20 - 0x0)
// Function MeshDescription.MeshDescriptionBase.SetVertexPosition
struct UMeshDescriptionBase_SetVertexPosition_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_890[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	struct FVector                               Position;                                          // 0x8(0x18)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.SetPolygonVertexInstances
struct UMeshDescriptionBase_SetPolygonVertexInstances_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_898[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexInstanceID>             VertexInstanceIDs;                                 // 0x8(0x10)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.SetPolygonPolygonGroup
struct UMeshDescriptionBase_SetPolygonPolygonGroup_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ReversePolygonFacing
struct UMeshDescriptionBase_ReversePolygonFacing_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ReserveNewVertices
struct UMeshDescriptionBase_ReserveNewVertices_Params
{
public:
	int32                                        NumberOfNewVertices;                               // 0x0(0x4)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ReserveNewVertexInstances
struct UMeshDescriptionBase_ReserveNewVertexInstances_Params
{
public:
	int32                                        NumberOfNewVertexInstances;                        // 0x0(0x4)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ReserveNewTriangles
struct UMeshDescriptionBase_ReserveNewTriangles_Params
{
public:
	int32                                        NumberOfNewTriangles;                              // 0x0(0x4)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ReserveNewPolygons
struct UMeshDescriptionBase_ReserveNewPolygons_Params
{
public:
	int32                                        NumberOfNewPolygons;                               // 0x0(0x4)(ConstParm, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ReserveNewPolygonGroups
struct UMeshDescriptionBase_ReserveNewPolygonGroups_Params
{
public:
	int32                                        NumberOfNewPolygonGroups;                          // 0x0(0x4)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ReserveNewEdges
struct UMeshDescriptionBase_ReserveNewEdges_Params
{
public:
	int32                                        NumberOfNewEdges;                                  // 0x0(0x4)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsVertexValid
struct UMeshDescriptionBase_IsVertexValid_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_8C3[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsVertexOrphaned
struct UMeshDescriptionBase_IsVertexOrphaned_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_8C9[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsVertexInstanceValid
struct UMeshDescriptionBase_IsVertexInstanceValid_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_8F0[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsTriangleValid
struct UMeshDescriptionBase_IsTriangleValid_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(ConstParm, Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_8F7[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsTrianglePartOfNgon
struct UMeshDescriptionBase_IsTrianglePartOfNgon_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_906[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsPolygonValid
struct UMeshDescriptionBase_IsPolygonValid_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_90B[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsPolygonGroupValid
struct UMeshDescriptionBase_IsPolygonGroupValid_Params
{
public:
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_91A[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x1 (0x1 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsEmpty
struct UMeshDescriptionBase_IsEmpty_Params
{
public:
	bool                                         ReturnValue;                                       // 0x0(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsEdgeValid
struct UMeshDescriptionBase_IsEdgeValid_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_964[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsEdgeInternalToPolygon
struct UMeshDescriptionBase_IsEdgeInternalToPolygon_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPolygonID                            PolygonID;                                         // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x8(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_970[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.IsEdgeInternal
struct UMeshDescriptionBase_IsEdgeInternal_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                         ReturnValue;                                       // 0x4(0x1)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_979[0x3];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexVertexInstances
struct UMeshDescriptionBase_GetVertexVertexInstances_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_984[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexInstanceID>             OutVertexInstanceIDs;                              // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x20 (0x20 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexPosition
struct UMeshDescriptionBase_GetVertexPosition_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_98F[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	struct FVector                               ReturnValue;                                       // 0x8(0x18)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexPairEdge
struct UMeshDescriptionBase_GetVertexPairEdge_Params
{
public:
	struct FVertexID                             VertexID0;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             VertexID1;                                         // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FEdgeID                               ReturnValue;                                       // 0x8(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexInstanceVertex
struct UMeshDescriptionBase_GetVertexInstanceVertex_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexInstancePairEdge
struct UMeshDescriptionBase_GetVertexInstancePairEdge_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID0;                                 // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexInstanceID                     VertexInstanceID1;                                 // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FEdgeID                               ReturnValue;                                       // 0x8(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexInstanceForTriangleVertex
struct UMeshDescriptionBase_GetVertexInstanceForTriangleVertex_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             VertexID;                                          // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexInstanceID                     ReturnValue;                                       // 0x8(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexInstanceForPolygonVertex
struct UMeshDescriptionBase_GetVertexInstanceForPolygonVertex_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             VertexID;                                          // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexInstanceID                     ReturnValue;                                       // 0x8(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexInstanceCount
struct UMeshDescriptionBase_GetVertexInstanceCount_Params
{
public:
	int32                                        ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexInstanceConnectedTriangles
struct UMeshDescriptionBase_GetVertexInstanceConnectedTriangles_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_9D2[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FTriangleID>                   OutConnectedTriangleIDs;                           // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexInstanceConnectedPolygons
struct UMeshDescriptionBase_GetVertexInstanceConnectedPolygons_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_9D5[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FPolygonID>                    OutConnectedPolygonIDs;                            // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexCount
struct UMeshDescriptionBase_GetVertexCount_Params
{
public:
	int32                                        ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexConnectedTriangles
struct UMeshDescriptionBase_GetVertexConnectedTriangles_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_9DC[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FTriangleID>                   OutConnectedTriangleIDs;                           // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexConnectedPolygons
struct UMeshDescriptionBase_GetVertexConnectedPolygons_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_9E4[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FPolygonID>                    OutConnectedPolygonIDs;                            // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexConnectedEdges
struct UMeshDescriptionBase_GetVertexConnectedEdges_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_9E9[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FEdgeID>                       OutEdgeIDs;                                        // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetVertexAdjacentVertices
struct UMeshDescriptionBase_GetVertexAdjacentVertices_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_9F1[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexID>                     OutAdjacentVertexIDs;                              // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTriangleVertices
struct UMeshDescriptionBase_GetTriangleVertices_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A06[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexID>                     OutVertexIDs;                                      // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTriangleVertexInstances
struct UMeshDescriptionBase_GetTriangleVertexInstances_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A0F[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexInstanceID>             OutVertexInstanceIDs;                              // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTriangleVertexInstance
struct UMeshDescriptionBase_GetTriangleVertexInstance_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        Index;                                             // 0x4(0x4)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexInstanceID                     ReturnValue;                                       // 0x8(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTrianglePolygonGroup
struct UMeshDescriptionBase_GetTrianglePolygonGroup_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPolygonGroupID                       ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTrianglePolygon
struct UMeshDescriptionBase_GetTrianglePolygon_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPolygonID                            ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTriangleEdges
struct UMeshDescriptionBase_GetTriangleEdges_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A2E[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FEdgeID>                       OutEdgeIDs;                                        // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTriangleCount
struct UMeshDescriptionBase_GetTriangleCount_Params
{
public:
	int32                                        ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetTriangleAdjacentTriangles
struct UMeshDescriptionBase_GetTriangleAdjacentTriangles_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A38[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FTriangleID>                   OutTriangleIDs;                                    // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonVertices
struct UMeshDescriptionBase_GetPolygonVertices_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A3C[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexID>                     OutVertexIDs;                                      // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonVertexInstances
struct UMeshDescriptionBase_GetPolygonVertexInstances_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A41[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexInstanceID>             OutVertexInstanceIDs;                              // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonTriangles
struct UMeshDescriptionBase_GetPolygonTriangles_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A47[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FTriangleID>                   OutTriangleIDs;                                    // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonPolygonGroup
struct UMeshDescriptionBase_GetPolygonPolygonGroup_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPolygonGroupID                       ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonPerimeterEdges
struct UMeshDescriptionBase_GetPolygonPerimeterEdges_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A4D[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FEdgeID>                       OutEdgeIDs;                                        // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonInternalEdges
struct UMeshDescriptionBase_GetPolygonInternalEdges_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A50[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FEdgeID>                       OutEdgeIDs;                                        // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonGroupPolygons
struct UMeshDescriptionBase_GetPolygonGroupPolygons_Params
{
public:
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A59[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FPolygonID>                    OutPolygonIDs;                                     // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonGroupCount
struct UMeshDescriptionBase_GetPolygonGroupCount_Params
{
public:
	int32                                        ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonCount
struct UMeshDescriptionBase_GetPolygonCount_Params
{
public:
	int32                                        ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetPolygonAdjacentPolygons
struct UMeshDescriptionBase_GetPolygonAdjacentPolygons_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A67[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FPolygonID>                    OutPolygonIDs;                                     // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumVertexVertexInstances
struct UMeshDescriptionBase_GetNumVertexVertexInstances_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumVertexInstanceConnectedTriangles
struct UMeshDescriptionBase_GetNumVertexInstanceConnectedTriangles_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumVertexInstanceConnectedPolygons
struct UMeshDescriptionBase_GetNumVertexInstanceConnectedPolygons_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumVertexConnectedTriangles
struct UMeshDescriptionBase_GetNumVertexConnectedTriangles_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumVertexConnectedPolygons
struct UMeshDescriptionBase_GetNumVertexConnectedPolygons_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumVertexConnectedEdges
struct UMeshDescriptionBase_GetNumVertexConnectedEdges_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumPolygonVertices
struct UMeshDescriptionBase_GetNumPolygonVertices_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumPolygonTriangles
struct UMeshDescriptionBase_GetNumPolygonTriangles_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumPolygonInternalEdges
struct UMeshDescriptionBase_GetNumPolygonInternalEdges_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumPolygonGroupPolygons
struct UMeshDescriptionBase_GetNumPolygonGroupPolygons_Params
{
public:
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumEdgeConnectedTriangles
struct UMeshDescriptionBase_GetNumEdgeConnectedTriangles_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetNumEdgeConnectedPolygons
struct UMeshDescriptionBase_GetNumEdgeConnectedPolygons_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetEdgeVertices
struct UMeshDescriptionBase_GetEdgeVertices_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(ConstParm, Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_A9E[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexID>                     OutVertexIDs;                                      // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetEdgeVertex
struct UMeshDescriptionBase_GetEdgeVertex_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	int32                                        VertexNumber;                                      // 0x4(0x4)(Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             ReturnValue;                                       // 0x8(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetEdgeCount
struct UMeshDescriptionBase_GetEdgeCount_Params
{
public:
	int32                                        ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetEdgeConnectedTriangles
struct UMeshDescriptionBase_GetEdgeConnectedTriangles_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_AAA[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FTriangleID>                   OutConnectedTriangleIDs;                           // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.GetEdgeConnectedPolygons
struct UMeshDescriptionBase_GetEdgeConnectedPolygons_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_AB2[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FPolygonID>                    OutConnectedPolygonIDs;                            // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.DeleteVertexInstance
struct UMeshDescriptionBase_DeleteVertexInstance_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_ABC[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexID>                     OrphanedVertices;                                  // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.DeleteVertex
struct UMeshDescriptionBase_DeleteVertex_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x38 (0x38 - 0x0)
// Function MeshDescription.MeshDescriptionBase.DeleteTriangle
struct UMeshDescriptionBase_DeleteTriangle_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_AC5[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FEdgeID>                       OrphanedEdges;                                     // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FVertexInstanceID>             OrphanedVertexInstances;                           // 0x18(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FPolygonGroupID>               OrphanedPolygonGroupsPtr;                          // 0x28(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.DeletePolygonGroup
struct UMeshDescriptionBase_DeletePolygonGroup_Params
{
public:
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x38 (0x38 - 0x0)
// Function MeshDescription.MeshDescriptionBase.DeletePolygon
struct UMeshDescriptionBase_DeletePolygon_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_AD4[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FEdgeID>                       OrphanedEdges;                                     // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FVertexInstanceID>             OrphanedVertexInstances;                           // 0x18(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FPolygonGroupID>               OrphanedPolygonGroups;                             // 0x28(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x18 (0x18 - 0x0)
// Function MeshDescription.MeshDescriptionBase.DeleteEdge
struct UMeshDescriptionBase_DeleteEdge_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_AD9[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexID>                     OrphanedVertices;                                  // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateVertexWithID
struct UMeshDescriptionBase_CreateVertexWithID_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateVertexInstanceWithID
struct UMeshDescriptionBase_CreateVertexInstanceWithID_Params
{
public:
	struct FVertexInstanceID                     VertexInstanceID;                                  // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             VertexID;                                          // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x8 (0x8 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateVertexInstance
struct UMeshDescriptionBase_CreateVertexInstance_Params
{
public:
	struct FVertexID                             VertexID;                                          // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexInstanceID                     ReturnValue;                                       // 0x4(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateVertex
struct UMeshDescriptionBase_CreateVertex_Params
{
public:
	struct FVertexID                             ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x28 (0x28 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateTriangleWithID
struct UMeshDescriptionBase_CreateTriangleWithID_Params
{
public:
	struct FTriangleID                           TriangleID;                                        // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FVertexInstanceID>             VertexInstanceIDs;                                 // 0x8(0x10)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)
	TArray<struct FEdgeID>                       NewEdgeIDs;                                        // 0x18(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x30 (0x30 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateTriangle
struct UMeshDescriptionBase_CreateTriangle_Params
{
public:
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_AF2[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexInstanceID>             VertexInstanceIDs;                                 // 0x8(0x10)(ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)
	TArray<struct FEdgeID>                       NewEdgeIDs;                                        // 0x18(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	struct FTriangleID                           ReturnValue;                                       // 0x28(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_AF3[0x4];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0x28 (0x28 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreatePolygonWithID
struct UMeshDescriptionBase_CreatePolygonWithID_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	TArray<struct FVertexInstanceID>             VertexInstanceIDs;                                 // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FEdgeID>                       NewEdgeIDs;                                        // 0x18(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreatePolygonGroupWithID
struct UMeshDescriptionBase_CreatePolygonGroupWithID_Params
{
public:
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreatePolygonGroup
struct UMeshDescriptionBase_CreatePolygonGroup_Params
{
public:
	struct FPolygonGroupID                       ReturnValue;                                       // 0x0(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x30 (0x30 - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreatePolygon
struct UMeshDescriptionBase_CreatePolygon_Params
{
public:
	struct FPolygonGroupID                       PolygonGroupID;                                    // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_B07[0x4];                                      // Fixing Size After Last Property  [ Dumper-7 ]
	TArray<struct FVertexInstanceID>             VertexInstanceIDs;                                 // 0x8(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	TArray<struct FEdgeID>                       NewEdgeIDs;                                        // 0x18(0x10)(Parm, OutParm, ZeroConstructor, NativeAccessSpecifierPublic)
	struct FPolygonID                            ReturnValue;                                       // 0x28(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                        Pad_B09[0x4];                                      // Fixing Size Of Struct [ Dumper-7 ]
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateEdgeWithID
struct UMeshDescriptionBase_CreateEdgeWithID_Params
{
public:
	struct FEdgeID                               EdgeID;                                            // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             VertexID0;                                         // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             VertexID1;                                         // 0x8(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0xC (0xC - 0x0)
// Function MeshDescription.MeshDescriptionBase.CreateEdge
struct UMeshDescriptionBase_CreateEdge_Params
{
public:
	struct FVertexID                             VertexID0;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FVertexID                             VertexID1;                                         // 0x4(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	struct FEdgeID                               ReturnValue;                                       // 0x8(0x4)(Parm, OutParm, ReturnParm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

// 0x4 (0x4 - 0x0)
// Function MeshDescription.MeshDescriptionBase.ComputePolygonTriangulation
struct UMeshDescriptionBase_ComputePolygonTriangulation_Params
{
public:
	struct FPolygonID                            PolygonID;                                         // 0x0(0x4)(Parm, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
};

}
}


