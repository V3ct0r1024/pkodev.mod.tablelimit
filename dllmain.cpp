#include <Windows.h>
#include <detours.h>

#include "pointer.h"
#include "hook.h"
#include "structure.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#include "loader.h"


namespace pkodev
{
    namespace global
    {
        // Table limits storage
        std::vector<limit> limits;
    }
}

// Load limits for .txt\.bin files from file
void LoadTableLimits(const std::string& path, 
    std::vector< std::pair<std::string, unsigned int> >& tables);

// Get limit from storage
int GetTableLimit(const std::string& table_name, int id_count);

// Entry point
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    // Nothing to do . . .
    return TRUE;
}

// Get mod infromation
void __cdecl GetModInformation(mod_info& info)
{
    strcpy_s(info.name, TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author, TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

// Start the mod
void __cdecl Start(const char* path)
{
    // Buffer for path to the config file
    char buf[MAX_PATH]{ 0x00 };

    // Build path to config file
    sprintf_s(buf, sizeof(buf), "%s\\%s.cfg", path, TOSTRING(MOD_NAME));

    // Load table limit from file
    std::vector< std::pair<std::string, unsigned int> > tables_cfg;
    LoadTableLimits(std::string(buf), tables_cfg);

    // Add table to the list
    auto add_table = [&tables_cfg](const std::string& name, LPVOID* original_func, LPVOID hook_func) -> void
    {
        // Get limit by table name
        auto max_size = [&tables_cfg](const std::string& name) -> unsigned int
        {
            // Search table by name
            auto it = std::find_if(tables_cfg.begin(), tables_cfg.end(),
                [&name](const std::pair<std::string, unsigned int>& p) { return (p.first == name); }
            );

            // Check that table is not found
            if ( it == tables_cfg.end() )
            {
                return 0;
            }

            return it->second;
        };

        // Check address of the original function
        if (*original_func == nullptr) { return; }

        // Check pointer to the hook function
        if (hook_func == nullptr) { return; }

        // Get max size
        unsigned int lim = max_size(name);

        // Check max size
        if (lim > 0) 
        {  
            // Search table in the list
            auto it = std::find_if(pkodev::global::limits.begin(), pkodev::global::limits.end(),
                [&name](const pkodev::limit& lim) { return (lim.name == name); }
            );

            // Check that table is found
            if ( it != pkodev::global::limits.end() )
            {
                // Update table
                it->original_func = original_func;
                it->hook_func = hook_func;
                it->max_size = lim;
            }
            else
            {
                // Insert a new table
                pkodev::global::limits.push_back( { name, lim, original_func, hook_func } );
            }
        }
    };

    // Binary tables list
    add_table("areaset",              &(PVOID&)pkodev::pointer::CAreaSet__CAreaSet,                         pkodev::hook::CAreaSet__CAreaSet);                         // 1.  areaset
    add_table("character_lvup",       &(PVOID&)pkodev::pointer::CLevelRecordSet__CLevelRecordSet,           pkodev::hook::CLevelRecordSet__CLevelRecordSet);           // 2.  character_lvup
    add_table("characterinfo",        &(PVOID&)pkodev::pointer::CChaRecordSet__CChaRecordSet,               pkodev::hook::CChaRecordSet__CChaRecordSet);               // 3.  characterinfo
    add_table("forgeitem",            &(PVOID&)pkodev::pointer::CForgeRecordSet__CForgeRecordSet,           pkodev::hook::CForgeRecordSet__CForgeRecordSet);           // 4.  forgeitem
    add_table("hairs",                &(PVOID&)pkodev::pointer::CHairRecordSet__CHairRecordSet,             pkodev::hook::CHairRecordSet__CHairRecordSet);             // 5.  hairs
    add_table("int_cha_item",         &(PVOID&)pkodev::pointer::CJobEquipRecordSet__CJobEquipRecordSet,     pkodev::hook::CJobEquipRecordSet__CJobEquipRecordSet);     // 6.  int_cha_item
    add_table("iteminfo",             &(PVOID&)pkodev::pointer::CItemRecordSet__CItemRecordSet,             pkodev::hook::CItemRecordSet__CItemRecordSet);             // 7.  iteminfo
    add_table("lifelvup",             &(PVOID&)pkodev::pointer::CLifeLvRecordSet__CLifeLvRecordSet,         pkodev::hook::CLifeLvRecordSet__CLifeLvRecordSet);         // 8.  lifelvup
    add_table("saillvup",             &(PVOID&)pkodev::pointer::CSailLvRecordSet__CSailLvRecordSet,         pkodev::hook::CSailLvRecordSet__CSailLvRecordSet);         // 9.  saillvup
    add_table("shipinfo",             &(PVOID&)pkodev::pointer::xShipSet__xShipSet,                         pkodev::hook::xShipSet__xShipSet);                         // 10. shipinfo
    add_table("shipiteminfo",         &(PVOID&)pkodev::pointer::xShipPartSet__xShipPartSet,                 pkodev::hook::xShipPartSet__xShipPartSet);                 // 11. shipiteminfo
    add_table("skilleff",             &(PVOID&)pkodev::pointer::CSkillStateRecordSet__CSkillStateRecordSet, pkodev::hook::CSkillStateRecordSet__CSkillStateRecordSet); // 12. skilleff
    add_table("skillinfo",            &(PVOID&)pkodev::pointer::CSkillRecordSet__CSkillRecordSet,           pkodev::hook::CSkillRecordSet__CSkillRecordSet);           // 13. skillinfo
    add_table("characterposeinfo",    &(PVOID&)pkodev::pointer::CPoseSet__CPoseSet,                         pkodev::hook::CPoseSet__CPoseSet);                         // 14. characterposeinfo
    add_table("chaticons",            &(PVOID&)pkodev::pointer::CChatIconSet__CChatIconSet,                 pkodev::hook::CChatIconSet__CChatIconSet);                 // 15. chaticons
    add_table("elfskillinfo",         &(PVOID&)pkodev::pointer::CElfSkillSet__CElfSkillSet,                 pkodev::hook::CElfSkillSet__CElfSkillSet);                 // 16. elfskillinfo
    add_table("eventsound",           &(PVOID&)pkodev::pointer::CEventSoundSet__CEventSoundSet,             pkodev::hook::CEventSoundSet__CEventSoundSet);             // 17. eventsound
    add_table("itempre",              &(PVOID&)pkodev::pointer::CItemPreSet__CItemPreSet,                   pkodev::hook::CItemPreSet__CItemPreSet);                   // 18. itempre
    add_table("itemrefineeffectinfo", &(PVOID&)pkodev::pointer::CItemRefineEffectSet__CItemRefineEffectSet, pkodev::hook::CItemRefineEffectSet__CItemRefineEffectSet); // 19. itemrefineeffectinfo
    add_table("itemrefineinfo",       &(PVOID&)pkodev::pointer::CItemRefineSet__CItemRefineSet,             pkodev::hook::CItemRefineSet__CItemRefineSet);             // 20. itemrefineinfo
    add_table("itemtype",             &(PVOID&)pkodev::pointer::CItemTypeSet__CItemTypeSet,                 pkodev::hook::CItemTypeSet__CItemTypeSet);                 // 21. itemtype
    add_table("magicgroupinfo",       &(PVOID&)pkodev::pointer::CGroup_ParamSet__CGroup_ParamSet,           pkodev::hook::CGroup_ParamSet__CGroup_ParamSet);           // 22. magicgroupinfo
    add_table("magicsingleinfo",      &(PVOID&)pkodev::pointer::CEff_ParamSet__CEff_ParamSet,               pkodev::hook::CEff_ParamSet__CEff_ParamSet);               // 23. magicsingleinfo
    add_table("mapinfo",              &(PVOID&)pkodev::pointer::CMapSet__CMapSet,                           pkodev::hook::CMapSet__CMapSet);                           // 24. mapinfo
    add_table("musicinfo",            &(PVOID&)pkodev::pointer::CMusicSet__CMusicSet,                       pkodev::hook::CMusicSet__CMusicSet);                       // 25. musicinfo
    add_table("notifyset",            &(PVOID&)pkodev::pointer::CNotifySet__CNotifySet,                     pkodev::hook::CNotifySet__CNotifySet);                     // 26. notifyset
    add_table("objevent",             &(PVOID&)pkodev::pointer::CEventRecordSet__CEventRecordSet,           pkodev::hook::CEventRecordSet__CEventRecordSet);           // 27. objevent
    add_table("resourceinfo",         &(PVOID&)pkodev::pointer::MPResourceSet__MPResourceSet,               pkodev::hook::MPResourceSet__MPResourceSet);               // 28. resourceinfo
    add_table("sceneffectinfo",       &(PVOID&)pkodev::pointer::CEffectSet__CEffectSet,                     pkodev::hook::CEffectSet__CEffectSet);                     // 29. sceneffectinfo
    add_table("sceneobjinfo",         &(PVOID&)pkodev::pointer::CSceneObjSet__CSceneObjSet,                 pkodev::hook::CSceneObjSet__CSceneObjSet);                 // 30. sceneobjinfo
    add_table("selectcha",            &(PVOID&)pkodev::pointer::CChaCreateSet__CChaCreateSet,               pkodev::hook::CChaCreateSet__CChaCreateSet);               // 31. selectcha
    add_table("serverset",            &(PVOID&)pkodev::pointer::CServerSet__CServerSet,                     pkodev::hook::CServerSet__CServerSet);                     // 32. serverset
    add_table("shadeinfo",            &(PVOID&)pkodev::pointer::CShadeSet__CShadeSet,                       pkodev::hook::CShadeSet__CShadeSet);                       // 33. shadeinfo
    add_table("stoneinfo",            &(PVOID&)pkodev::pointer::CStoneSet__CStoneSet,                       pkodev::hook::CStoneSet__CStoneSet);                       // 34. stoneinfo
    add_table("terraininfo",          &(PVOID&)pkodev::pointer::MPTerrainSet__MPTerrainSet,                 pkodev::hook::MPTerrainSet__MPTerrainSet);                 // 35. terraininfo

    // Check that list has tables
    if ( pkodev::global::limits.empty() == false )
    {
        // Detours routine
        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        // Set hooks for available tables
        for ( const pkodev::limit& lim : pkodev::global::limits )
        {
            // Set hook
            DetourAttach(lim.original_func, lim.hook_func);
        }
     
        // Commit changes
        DetourTransactionCommit();
    }

    // Write welcome message
    std::cout << "[" << TOSTRING(MOD_NAME) << "] Table limit ver. " << TOSTRING(MOD_VERSION) << " by " << TOSTRING(MOD_AUTHOR) << std::endl;
}

// Stop the mod
void __cdecl Stop()
{
    // Check that list has tables
    if ( pkodev::global::limits.empty() == false )
    {
        // Detours routine
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        // Remove hooks
        for ( const pkodev::limit& lim : pkodev::global::limits )
        {
            // Remove hook
            DetourDetach(lim.original_func, lim.hook_func);
        }

        // Commit changes
        DetourTransactionCommit();
    }
}

// Load limits for .txt\.bin files from file
void LoadTableLimits(const std::string& path, std::vector< std::pair<std::string, unsigned int> >& tables)
{
    // Clear tables list
    tables.clear();

    // Open a file
    std::ifstream file(path, std::ifstream::in);

    // Check that file is open
    if ( file.is_open() == false )
    {
        // Can't open file file
        return;
    }

    // Current line that read from the file
    std::string line{ "" };

    // Read lines from file
    while ( getline(file, line) )
    {
        // Remove spaces from line
        line.erase( std::remove_if( line.begin(), line.end(), isspace ), line.end() );

        // Check that line is not empty
        if ( line.empty() == true )
        {
            // Skip line
            continue;
        }

        // Convert the line to lower case one
        std::transform( line.begin(), line.end(), line.begin(), std::tolower );

        // Search for symbol '='
        std::size_t pos = line.find('=');

        // Check that the symbol is found
        if (pos == std::string::npos)
        {
            // Skip the line
            continue;
        }

        // Get table max size
        unsigned int max_size = 0;
        try
        {
            // Trying convert std::string to unsigned int
            max_size = std::stoul(
                line.substr(pos + 1, line.length() - pos)
            );
        }
        catch (...)
        {
            // Conversion error
            continue;
        }

        // Get table name
        std::string name = line.substr(0, pos);

        // Search table name in the list
        auto it = std::find_if(tables.begin(), tables.end(),
            [&name](const std::pair<std::string, unsigned int>& p) { return (p.first == name); }
        );

        // Check that table is not found
        if ( it != tables.end() )
        {
            // Update table
            it->second = max_size;
        }  
        else
        {
            // Add table in the list
            tables.push_back( { name, max_size } );
        }
    }

    // Close the file
    file.close();
}

// Get limit for specified table
int GetTableLimit(const std::string& table_name, int id_count)
{
    // Search limit by table name in storage
    const auto it = std::find_if(pkodev::global::limits.begin(), pkodev::global::limits.end(),
        [&table_name](const pkodev::limit& lim) { return (lim.name == table_name);  }
    );

    // Check that limit is found
    if ( it != pkodev::global::limits.end() )
    {
        // Write a message
        std::cout << "[" << TOSTRING(MOD_NAME) << "] Limit for table '" << table_name << "' has been changed: " << id_count << " -> " << it->max_size << std::endl;

        // Return new limit
        return static_cast<int>( it->max_size );
    }

    // Return old limit
    return id_count;
}

// CAreaSet::CAreaSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CAreaSet__CAreaSet(void* This, void* NotUsed,
    int nIDStart, int nIDCnt)
{
    // Call original function CAreaSet::CAreaSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CAreaSet__CAreaSet( This, nIDStart,
        GetTableLimit("areaset", nIDCnt) );
}

// CLevelRecordSet::CLevelRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CLevelRecordSet__CLevelRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CLevelRecordSet::CLevelRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CLevelRecordSet__CLevelRecordSet( This, nIDStart,
        GetTableLimit("character_lvup", nIDCnt), nCol );
}

// CChaRecordSet::CChaRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CChaRecordSet__CChaRecordSet(void* This, void* NotUsed,
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CChaRecordSet::CChaRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CChaRecordSet__CChaRecordSet( This, nIDStart,
        GetTableLimit("characterinfo", nIDCnt), nCol );
}

// CForgeRecordSet::CForgeRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CForgeRecordSet__CForgeRecordSet(void* This, void* NotUsed,
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CForgeRecordSet::CForgeRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CForgeRecordSet__CForgeRecordSet( This, nIDStart,
        GetTableLimit("forgeitem", nIDCnt), nCol );
}

// CHairRecordSet::CHairRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CHairRecordSet__CHairRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CHairRecordSet::CHairRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CHairRecordSet__CHairRecordSet( This, nIDStart,
        GetTableLimit("hairs", nIDCnt), nCol );
}

// CJobEquipRecordSet::CJobEquipRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CJobEquipRecordSet__CJobEquipRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CJobEquipRecordSet::CJobEquipRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CJobEquipRecordSet__CJobEquipRecordSet( This, nIDStart,
        GetTableLimit("int_cha_item", nIDCnt), nCol );
}

// CItemRecordSet::CItemRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CItemRecordSet__CItemRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CItemRecordSet::CItemRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CItemRecordSet__CItemRecordSet( This, nIDStart,
        GetTableLimit("iteminfo", nIDCnt), nCol );
}

// CLifeLvRecordSet::CLifeLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CLifeLvRecordSet__CLifeLvRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CLifeLvRecordSet::CLifeLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CLifeLvRecordSet__CLifeLvRecordSet( This, nIDStart,
        GetTableLimit("lifelvup", nIDCnt), nCol );
}

// CSailLvRecordSet::CSailLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CSailLvRecordSet__CSailLvRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CSailLvRecordSet::CSailLvRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CSailLvRecordSet__CSailLvRecordSet( This, nIDStart,
        GetTableLimit("saillvup", nIDCnt), nCol );
}

// xShipSet::xShipSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::xShipSet__xShipSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt)
{
    // Call original function xShipSet::xShipSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::xShipSet__xShipSet( This, nIDStart,
        GetTableLimit("shipinfo", nIDCnt) );
}

// xShipPartSet::xShipPartSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::xShipPartSet__xShipPartSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt)
{
    // Call original function xShipPartSet::xShipPartSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::xShipPartSet__xShipPartSet( This, nIDStart,
        GetTableLimit("shipiteminfo", nIDCnt) );
}

// CSkillStateRecordSet::CSkillStateRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CSkillStateRecordSet__CSkillStateRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CSkillStateRecordSet::CSkillStateRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CSkillStateRecordSet__CSkillStateRecordSet( This, nIDStart,
        GetTableLimit("skilleff", nIDCnt), nCol );
}

// CSkillRecordSet::CSkillRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CSkillRecordSet__CSkillRecordSet(void* This, void* NotUsed, 
    int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CSkillRecordSet::CSkillRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
    return pkodev::pointer::CSkillRecordSet__CSkillRecordSet( This, nIDStart, 
        GetTableLimit("skillinfo", nIDCnt), nCol );
}


// CPoseSet::CPoseSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CPoseSet__CPoseSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CPoseSet::CPoseSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CPoseSet__CPoseSet( This, nIDStart,
        GetTableLimit("characterposeinfo", nIDCnt) );
}

// CChatIconSet::CChatIconSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CChatIconSet__CChatIconSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CChatIconSet::CChatIconSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CChatIconSet__CChatIconSet( This, nIDStart,
        GetTableLimit("chaticons", nIDCnt) );
}

// CElfSkillSet::CElfSkillSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CElfSkillSet__CElfSkillSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CElfSkillSet::CElfSkillSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CElfSkillSet__CElfSkillSet( This, nIDStart,
        GetTableLimit("elfskillinfo", nIDCnt) );
}

// CEventSoundSet::CEventSoundSet(int nIDStart, int nIDCnt, int nCol = 8)
void* __fastcall pkodev::hook::CEventSoundSet__CEventSoundSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CEventSoundSet::CEventSoundSet(int nIDStart, int nIDCnt, int nCol)
    return pkodev::pointer::CEventSoundSet__CEventSoundSet( This, nIDStart,
        GetTableLimit("eventsound", nIDCnt), nCol );
}

// CItemPreSet::CItemPreSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CItemPreSet__CItemPreSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CItemPreSet::CItemPreSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CItemPreSet__CItemPreSet( This, nIDStart,
        GetTableLimit("itempre", nIDCnt) );
}

// CItemRefineEffectSet::CItemRefineEffectSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CItemRefineEffectSet__CItemRefineEffectSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CItemRefineEffectSet::CItemRefineEffectSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CItemRefineEffectSet__CItemRefineEffectSet( This, nIDStart,
        GetTableLimit("itemrefineeffectinfo", nIDCnt) );
}

// CItemRefineSet::CItemRefineSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CItemRefineSet__CItemRefineSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CItemRefineSet::CItemRefineSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CItemRefineSet__CItemRefineSet( This, nIDStart,
        GetTableLimit("itemrefineinfo", nIDCnt) );
}

// CItemTypeSet::CItemTypeSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CItemTypeSet__CItemTypeSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CItemTypeSet::CItemTypeSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CItemTypeSet__CItemTypeSet( This, nIDStart,
        GetTableLimit("itemtype", nIDCnt) );
}

// CGroup_ParamSet::CGroup_ParamSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CGroup_ParamSet__CGroup_ParamSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CGroup_ParamSet::CGroup_ParamSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CGroup_ParamSet__CGroup_ParamSet( This, nIDStart,
        GetTableLimit("magicgroupinfo", nIDCnt) );
}

// CEff_ParamSet::CEff_ParamSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CEff_ParamSet__CEff_ParamSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CEff_ParamSet::CEff_ParamSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CEff_ParamSet__CEff_ParamSet( This, nIDStart,
        GetTableLimit("magicsingleinfo", nIDCnt) );
}

// CMapSet::CMapSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CMapSet__CMapSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CMapSet::CMapSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CMapSet__CMapSet( This, nIDStart,
        GetTableLimit("mapinfo", nIDCnt) );
}

// CMusicSet::CMusicSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CMusicSet__CMusicSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CMusicSet::CMusicSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CMusicSet__CMusicSet( This, nIDStart,
        GetTableLimit("musicinfo", nIDCnt) );
}

// CNotifySet::CNotifySet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CNotifySet__CNotifySet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CNotifySet::CNotifySet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CNotifySet__CNotifySet( This, nIDStart,
        GetTableLimit("notifyset", nIDCnt) );
}

// CEventRecordSet::CEventRecordSet(int nIDStart, int nIDCnt, int nCol = 128)
void* __fastcall pkodev::hook::CEventRecordSet__CEventRecordSet(void* This, void* NotUsed, int nIDStart, int nIDCnt, int nCol)
{
    // Call original function CEventRecordSet::CEventRecordSet(int nIDStart, int nIDCnt, int nCol)
    return pkodev::pointer::CEventRecordSet__CEventRecordSet( This, nIDStart,
        GetTableLimit("objevent", nIDCnt), nCol );
}

// MPResourceSet::MPResourceSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::MPResourceSet__MPResourceSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function MPResourceSet::MPResourceSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::MPResourceSet__MPResourceSet( This, nIDStart,
        GetTableLimit("resourceinfo", nIDCnt) );
}

// CEffectSet::CEffectSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CEffectSet__CEffectSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CEffectSet::CEffectSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CEffectSet__CEffectSet( This, nIDStart,
        GetTableLimit("sceneffectinfo", nIDCnt) );
}

// CSceneObjSet::CSceneObjSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CSceneObjSet__CSceneObjSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CSceneObjSet::CSceneObjSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CSceneObjSet__CSceneObjSet( This, nIDStart,
        GetTableLimit("sceneobjinfo", nIDCnt) );
}

// CChaCreateSet::CChaCreateSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CChaCreateSet__CChaCreateSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CChaCreateSet::CChaCreateSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CChaCreateSet__CChaCreateSet( This, nIDStart,
        GetTableLimit("selectcha", nIDCnt) );
}

// CChaCreateSet::CServerSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CServerSet__CServerSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CServerSet::CServerSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CServerSet__CServerSet( This, nIDStart,
        GetTableLimit("serverset", nIDCnt) );
}

// CShadeSet::CShadeSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CShadeSet__CShadeSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CShadeSet::CShadeSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CShadeSet__CShadeSet( This, nIDStart,
        GetTableLimit("shadeinfo", nIDCnt) );
}

// CStoneSet::CStoneSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::CStoneSet__CStoneSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function CStoneSet::CStoneSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::CStoneSet__CStoneSet( This, nIDStart,
        GetTableLimit("stoneinfo", nIDCnt) );
}

// MPTerrainSet::MPTerrainSet(int nIDStart, int nIDCnt)
void* __fastcall pkodev::hook::MPTerrainSet__MPTerrainSet(void* This, void* NotUsed, int nIDStart, int nIDCnt)
{
    // Call original function MPTerrainSet::MPTerrainSet(int nIDStart, int nIDCnt)
    return pkodev::pointer::MPTerrainSet__MPTerrainSet (This, nIDStart,
        GetTableLimit("terraininfo", nIDCnt) );
}