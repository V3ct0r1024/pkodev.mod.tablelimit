#pragma once
#include "address.h"

namespace pkodev
{
	namespace pointer
	{
		// CAreaSet::CAreaSet(int nIDStart, int nIDCnt)
		typedef void*(__thiscall* CAreaSet__CAreaSet__Ptr)(void*, int, int);
		CAreaSet__CAreaSet__Ptr CAreaSet__CAreaSet = (CAreaSet__CAreaSet__Ptr)(void*)(address::MOD_EXE_VERSION::CAreaSet__CAreaSet);

		// CLevelRecordSet::CLevelRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CLevelRecordSet__CLevelRecordSet__Ptr)(void*, int, int, int);
		CLevelRecordSet__CLevelRecordSet__Ptr CLevelRecordSet__CLevelRecordSet = (CLevelRecordSet__CLevelRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CLevelRecordSet__CLevelRecordSet);

		// CChaRecordSet::CChaRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CChaRecordSet__CChaRecordSet__Ptr)(void*, int, int, int);
		CChaRecordSet__CChaRecordSet__Ptr CChaRecordSet__CChaRecordSet = (CChaRecordSet__CChaRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CChaRecordSet__CChaRecordSet);

		// CForgeRecordSet::CForgeRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CForgeRecordSet__CForgeRecordSet__Ptr)(void*, int, int, int);
		CForgeRecordSet__CForgeRecordSet__Ptr CForgeRecordSet__CForgeRecordSet = (CForgeRecordSet__CForgeRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CForgeRecordSet__CForgeRecordSet);

		// CHairRecordSet::CHairRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CHairRecordSet__CHairRecordSet__Ptr)(void*, int, int, int);
		CHairRecordSet__CHairRecordSet__Ptr CHairRecordSet__CHairRecordSet = (CHairRecordSet__CHairRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CHairRecordSet__CHairRecordSet);

		// CJobEquipRecordSet::CJobEquipRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CJobEquipRecordSet__CJobEquipRecordSet__Ptr)(void*, int, int, int);
		CJobEquipRecordSet__CJobEquipRecordSet__Ptr CJobEquipRecordSet__CJobEquipRecordSet = (CJobEquipRecordSet__CJobEquipRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CJobEquipRecordSet__CJobEquipRecordSet);
		
		// CItemRecordSet::CItemRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CItemRecordSet__CItemRecordSet__Ptr)(void*, int, int, int);
		CItemRecordSet__CItemRecordSet__Ptr CItemRecordSet__CItemRecordSet = (CItemRecordSet__CItemRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CItemRecordSet__CItemRecordSet);

		// CLifeLvRecordSet::CLifeLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CLifeLvRecordSet__CLifeLvRecordSet__Ptr)(void*, int, int, int);
		CLifeLvRecordSet__CLifeLvRecordSet__Ptr CLifeLvRecordSet__CLifeLvRecordSet = (CLifeLvRecordSet__CLifeLvRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CLifeLvRecordSet__CLifeLvRecordSet);

		// CSailLvRecordSet::CSailLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CSailLvRecordSet__CSailLvRecordSet__Ptr)(void*, int, int, int);
		CSailLvRecordSet__CSailLvRecordSet__Ptr CSailLvRecordSet__CSailLvRecordSet = (CSailLvRecordSet__CSailLvRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CSailLvRecordSet__CSailLvRecordSet);

		// xShipSet::xShipSet(int nIDStart, int nIDCnt)
		typedef void*(__thiscall* xShipSet__xShipSet__Ptr)(void*, int, int);
		xShipSet__xShipSet__Ptr xShipSet__xShipSet = (xShipSet__xShipSet__Ptr)(void*)(address::MOD_EXE_VERSION::xShipSet__xShipSet);

		// xShipPartSet::xShipPartSet(int nIDStart, int nIDCnt)
		typedef void*(__thiscall* xShipPartSet__xShipPartSet__Ptr)(void*, int, int);
		xShipPartSet__xShipPartSet__Ptr xShipPartSet__xShipPartSet = (xShipPartSet__xShipPartSet__Ptr)(void*)(address::MOD_EXE_VERSION::xShipPartSet__xShipPartSet);

		// CSkillStateRecordSet::CSkillStateRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CSkillStateRecordSet__CSkillStateRecordSet__Ptr)(void*, int, int, int);
		CSkillStateRecordSet__CSkillStateRecordSet__Ptr CSkillStateRecordSet__CSkillStateRecordSet = (CSkillStateRecordSet__CSkillStateRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CSkillStateRecordSet__CSkillStateRecordSet);

		// CSkillRecordSet::CSkillRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void*(__thiscall* CSkillRecordSet__CSkillRecordSet__Ptr)(void*, int, int, int);
		CSkillRecordSet__CSkillRecordSet__Ptr CSkillRecordSet__CSkillRecordSet = (CSkillRecordSet__CSkillRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CSkillRecordSet__CSkillRecordSet);



		// CPoseSet::CPoseSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CPoseSet__CPoseSet__Ptr)(void*, int, int);
		CPoseSet__CPoseSet__Ptr CPoseSet__CPoseSet = (CPoseSet__CPoseSet__Ptr)(void*)(address::MOD_EXE_VERSION::CPoseSet__CPoseSet);

		// CChatIconSet::CChatIconSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CChatIconSet__CChatIconSet__Ptr)(void*, int, int);
		CChatIconSet__CChatIconSet__Ptr CChatIconSet__CChatIconSet = (CChatIconSet__CChatIconSet__Ptr)(void*)(address::MOD_EXE_VERSION::CChatIconSet__CChatIconSet);

		// CElfSkillSet::CElfSkillSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CElfSkillSet__CElfSkillSet__Ptr)(void*, int, int);
		CElfSkillSet__CElfSkillSet__Ptr CElfSkillSet__CElfSkillSet = (CElfSkillSet__CElfSkillSet__Ptr)(void*)(address::MOD_EXE_VERSION::CElfSkillSet__CElfSkillSet);

		// CEventSoundSet::CEventSoundSet(int nIDStart, int nIDCnt, int nCol = 8)
		typedef void* (__thiscall* CEventSoundSet__CEventSoundSet__Ptr)(void*, int, int, int);
		CEventSoundSet__CEventSoundSet__Ptr CEventSoundSet__CEventSoundSet = (CEventSoundSet__CEventSoundSet__Ptr)(void*)(address::MOD_EXE_VERSION::CEventSoundSet__CEventSoundSet);

		// CItemPreSet::CItemPreSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CItemPreSet__CItemPreSet__Ptr)(void*, int, int);
		CItemPreSet__CItemPreSet__Ptr CItemPreSet__CItemPreSet = (CItemPreSet__CItemPreSet__Ptr)(void*)(address::MOD_EXE_VERSION::CItemPreSet__CItemPreSet);

		// CItemRefineEffectSet::CItemRefineEffectSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CItemRefineEffectSet__CItemRefineEffectSet__Ptr)(void*, int, int);
		CItemRefineEffectSet__CItemRefineEffectSet__Ptr CItemRefineEffectSet__CItemRefineEffectSet = (CItemRefineEffectSet__CItemRefineEffectSet__Ptr)(void*)(address::MOD_EXE_VERSION::CItemRefineEffectSet__CItemRefineEffectSet);

		// CItemRefineSet::CItemRefineSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CItemRefineSet__CItemRefineSet__Ptr)(void*, int, int);
		CItemRefineSet__CItemRefineSet__Ptr CItemRefineSet__CItemRefineSet = (CItemRefineSet__CItemRefineSet__Ptr)(void*)(address::MOD_EXE_VERSION::CItemRefineSet__CItemRefineSet);

		// CItemTypeSet::CItemTypeSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CItemTypeSet__CItemTypeSet__Ptr)(void*, int, int);
		CItemTypeSet__CItemTypeSet__Ptr CItemTypeSet__CItemTypeSet = (CItemTypeSet__CItemTypeSet__Ptr)(void*)(address::MOD_EXE_VERSION::CItemTypeSet__CItemTypeSet);

		// CGroup_ParamSet::CGroup_ParamSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CGroup_ParamSet__CGroup_ParamSet__Ptr)(void*, int, int);
		CGroup_ParamSet__CGroup_ParamSet__Ptr CGroup_ParamSet__CGroup_ParamSet = (CGroup_ParamSet__CGroup_ParamSet__Ptr)(void*)( (address::MOD_EXE_VERSION::CGroup_ParamSet__CGroup_ParamSet != 0x00000000) ? *reinterpret_cast<const unsigned int*>(address::MOD_EXE_VERSION::CGroup_ParamSet__CGroup_ParamSet) : 0x00000000 );

		// CEff_ParamSet::CEff_ParamSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CEff_ParamSet__CEff_ParamSet__Ptr)(void*, int, int);
		CEff_ParamSet__CEff_ParamSet__Ptr CEff_ParamSet__CEff_ParamSet = (CEff_ParamSet__CEff_ParamSet__Ptr)(void*)( (address::MOD_EXE_VERSION::CEff_ParamSet__CEff_ParamSet  != 0x00000000) ? *reinterpret_cast<const unsigned int*>(address::MOD_EXE_VERSION::CEff_ParamSet__CEff_ParamSet) : 0x00000000 );

		// CMapSet::CMapSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CMapSet__CMapSet__Ptr)(void*, int, int);
		CMapSet__CMapSet__Ptr CMapSet__CMapSet = (CMapSet__CMapSet__Ptr)(void*)(address::MOD_EXE_VERSION::CMapSet__CMapSet);

		// CMusicSet::CMusicSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CMusicSet__CMusicSet__Ptr)(void*, int, int);
		CMusicSet__CMusicSet__Ptr CMusicSet__CMusicSet = (CMusicSet__CMusicSet__Ptr)(void*)(address::MOD_EXE_VERSION::CMusicSet__CMusicSet);

		// CNotifySet::CNotifySet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CNotifySet__CNotifySet__Ptr)(void*, int, int);
		CNotifySet__CNotifySet__Ptr CNotifySet__CNotifySet = (CNotifySet__CNotifySet__Ptr)(void*)(address::MOD_EXE_VERSION::CNotifySet__CNotifySet);

		// CEventRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		typedef void* (__thiscall* CEventRecordSet__CEventRecordSet__Ptr)(void*, int, int, int);
		CEventRecordSet__CEventRecordSet__Ptr CEventRecordSet__CEventRecordSet = (CEventRecordSet__CEventRecordSet__Ptr)(void*)(address::MOD_EXE_VERSION::CEventRecordSet__CEventRecordSet);

		// MPResourceSet::MPResourceSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* MPResourceSet__MPResourceSet__Ptr)(void*, int, int);
		MPResourceSet__MPResourceSet__Ptr MPResourceSet__MPResourceSet = (MPResourceSet__MPResourceSet__Ptr)(void*)( (address::MOD_EXE_VERSION::MPResourceSet__MPResourceSet != 0x00000000) ? *reinterpret_cast<const unsigned int*>(address::MOD_EXE_VERSION::MPResourceSet__MPResourceSet) : 0x00000000);

		// CEffectSet::CEffectSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CEffectSet__CEffectSet__Ptr)(void*, int, int);
		CEffectSet__CEffectSet__Ptr CEffectSet__CEffectSet = (CEffectSet__CEffectSet__Ptr)(void*)(address::MOD_EXE_VERSION::CEffectSet__CEffectSet);

		// CSceneObjSet::CSceneObjSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CSceneObjSet__CSceneObjSet__Ptr)(void*, int, int);
		CSceneObjSet__CSceneObjSet__Ptr CSceneObjSet__CSceneObjSet = (CSceneObjSet__CSceneObjSet__Ptr)(void*)(address::MOD_EXE_VERSION::CSceneObjSet__CSceneObjSet);

		// CChaCreateSet::CChaCreateSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CChaCreateSet__CChaCreateSet__Ptr)(void*, int, int);
		CChaCreateSet__CChaCreateSet__Ptr CChaCreateSet__CChaCreateSet = (CChaCreateSet__CChaCreateSet__Ptr)(void*)(address::MOD_EXE_VERSION::CChaCreateSet__CChaCreateSet);

		// CChaCreateSet::CServerSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CServerSet__CServerSet__Ptr)(void*, int, int);
		CServerSet__CServerSet__Ptr CServerSet__CServerSet = (CServerSet__CServerSet__Ptr)(void*)(address::MOD_EXE_VERSION::CServerSet__CServerSet);

		// CShadeSet::CShadeSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CShadeSet__CShadeSet__Ptr)(void*, int, int);
		CShadeSet__CShadeSet__Ptr CShadeSet__CShadeSet = (CShadeSet__CShadeSet__Ptr)(void*)(address::MOD_EXE_VERSION::CShadeSet__CShadeSet);

		// CStoneSet::CStoneSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* CStoneSet__CStoneSet__Ptr)(void*, int, int);
		CStoneSet__CStoneSet__Ptr CStoneSet__CStoneSet = (CStoneSet__CStoneSet__Ptr)(void*)(address::MOD_EXE_VERSION::CStoneSet__CStoneSet);

		// MPTerrainSet::MPTerrainSet(int nIDStart, int nIDCnt)
		typedef void* (__thiscall* MPTerrainSet__MPTerrainSet__Ptr)(void*, int, int);
		MPTerrainSet__MPTerrainSet__Ptr MPTerrainSet__MPTerrainSet = (MPTerrainSet__MPTerrainSet__Ptr)(void*)( (address::MOD_EXE_VERSION::MPTerrainSet__MPTerrainSet  != 0x00000000) ? *reinterpret_cast<const unsigned int *>(address::MOD_EXE_VERSION::MPTerrainSet__MPTerrainSet) : 0x00000000 );
	}
}