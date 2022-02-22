#pragma once

namespace pkodev
{
	namespace hook
	{
		// CAreaSet::CAreaSet(int nIDStart, int nIDCnt)
		void* __fastcall CAreaSet__CAreaSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CLevelRecordSet::CLevelRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CLevelRecordSet__CLevelRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);
		
		// CChaRecordSet::CChaRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CChaRecordSet__CChaRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CForgeRecordSet::CForgeRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CForgeRecordSet__CForgeRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CHairRecordSet::CHairRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CHairRecordSet__CHairRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CJobEquipRecordSet::CJobEquipRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CJobEquipRecordSet__CJobEquipRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CItemRecordSet::CItemRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CItemRecordSet__CItemRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CLifeLvRecordSet::CLifeLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CLifeLvRecordSet__CLifeLvRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CSailLvRecordSet::CSailLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CSailLvRecordSet__CSailLvRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// xShipSet::xShipSet(int nIDStart, int nIDCnt)
		void* __fastcall xShipSet__xShipSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// xShipPartSet::xShipPartSet(int nIDStart, int nIDCnt)
		void* __fastcall xShipPartSet__xShipPartSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CSkillStateRecordSet::CSkillStateRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CSkillStateRecordSet__CSkillStateRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CSkillRecordSet::CSkillRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CSkillRecordSet__CSkillRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CPoseSet::CPoseSet(int nIDStart, int nIDCnt)
		void* __fastcall CPoseSet__CPoseSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CChatIconSet::CChatIconSet(int nIDStart, int nIDCnt)
		void* __fastcall CChatIconSet__CChatIconSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CElfSkillSet::CElfSkillSet(int nIDStart, int nIDCnt)
		void* __fastcall CElfSkillSet__CElfSkillSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CEventSoundSet::CEventSoundSet(int nIDStart, int nIDCnt, int nCol = 8)
		void* __fastcall CEventSoundSet__CEventSoundSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// CItemPreSet::CItemPreSet(int nIDStart, int nIDCnt)
		void* __fastcall CItemPreSet__CItemPreSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CItemRefineEffectSet::CItemRefineEffectSet(int nIDStart, int nIDCnt)
		void* __fastcall CItemRefineEffectSet__CItemRefineEffectSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CItemRefineSet::CItemRefineSet(int nIDStart, int nIDCnt)
		void* __fastcall CItemRefineSet__CItemRefineSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CItemTypeSet::CItemTypeSet(int nIDStart, int nIDCnt)
		void* __fastcall CItemTypeSet__CItemTypeSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CGroup_ParamSet::CGroup_ParamSet(int nIDStart, int nIDCnt)
		void* __fastcall CGroup_ParamSet__CGroup_ParamSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CEff_ParamSet::CEff_ParamSet(int nIDStart, int nIDCnt)
		void* __fastcall CEff_ParamSet__CEff_ParamSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CMapSet::CMapSet(int nIDStart, int nIDCnt)
		void* __fastcall CMapSet__CMapSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CMusicSet::CMusicSet(int nIDStart, int nIDCnt)
		void* __fastcall CMusicSet__CMusicSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CNotifySet::CNotifySet(int nIDStart, int nIDCnt)
		void* __fastcall CNotifySet__CNotifySet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CEventRecordSet::CEventRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
		void* __fastcall CEventRecordSet__CEventRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol);

		// MPResourceSet::MPResourceSet(int nIDStart, int nIDCnt)
		void* __fastcall MPResourceSet__MPResourceSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CEffectSet::CEffectSet(int nIDStart, int nIDCnt)
		void* __fastcall CEffectSet__CEffectSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CSceneObjSet::CSceneObjSet(int nIDStart, int nIDCnt)
		void* __fastcall CSceneObjSet__CSceneObjSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CChaCreateSet::CChaCreateSet(int nIDStart, int nIDCnt)
		void* __fastcall CChaCreateSet__CChaCreateSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CChaCreateSet::CServerSet(int nIDStart, int nIDCnt)
		void* __fastcall CServerSet__CServerSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CShadeSet::CShadeSet(int nIDStart, int nIDCnt)
		void* __fastcall CShadeSet__CShadeSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// CStoneSet::CStoneSet(int nIDStart, int nIDCnt)
		void* __fastcall CStoneSet__CStoneSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);

		// MPTerrainSet::MPTerrainSet(int nIDStart, int nIDCnt)
		void* __fastcall MPTerrainSet__MPTerrainSet(void* This, void* NotUsed, int nIDStart, int nIDCnt);
	}
}