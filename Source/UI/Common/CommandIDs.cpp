/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "CommandIDs.h"

// Implements compile-time FNV1a hash:
constexpr uint32 fnv1a_32_val = 0x811c9dc5;
constexpr uint64 fnv1a_32_prime = 0x1000193;
inline constexpr uint32 Hash(const char *const str, const uint32 value = fnv1a_32_val) noexcept {
    return (str[0] == '\0') ? value : Hash(&str[1], uint32(value ^ uint32(str[0])) * fnv1a_32_prime);
}

int CommandIDs::getIdForName(const String &command)
{
    switch (Hash(command.toRawUTF8()))
    {
    case Hash("Back"):
        return Back;
    case Hash("Cancel"):
        return Cancel;
    case Hash("Browse"):
        return Browse;
    case Hash("IconButtonPressed"):
        return IconButtonPressed;
    case Hash("MenuButtonPressed"):
        return MenuButtonPressed;
    case Hash("RootTreeItemPressed"):
        return RootTreeItemPressed;
    case Hash("HideDialog"):
        return HideDialog;
    case Hash("HideCallout"):
        return HideCallout;
    case Hash("ChangeTimeSignature"):
        return ChangeTimeSignature;
    case Hash("ChangeTimeSignatureConfirmed"):
        return ChangeTimeSignatureConfirmed;
    case Hash("DeleteTimeSignature"):
        return DeleteTimeSignature;
    case Hash("RenameAnnotation"):
        return RenameAnnotation;
    case Hash("RenameAnnotationConfirmed"):
        return RenameAnnotationConfirmed;
    case Hash("SetAnnotationColour"):
        return SetAnnotationColour;
    case Hash("DeleteAnnotation"):
        return DeleteAnnotation;
    case Hash("AddAnnotation"):
        return AddAnnotation;
    case Hash("AddAnnotationConfirmed"):
        return AddAnnotationConfirmed;
    case Hash("AddTimeSignature"):
        return AddTimeSignature;
    case Hash("AddTimeSignatureConfirmed"):
        return AddTimeSignatureConfirmed;
    case Hash("AddKeySignature"):
        return AddKeySignature;
    case Hash("AddKeySignatureConfirmed"):
        return AddKeySignatureConfirmed;
    case Hash("JumpToAnnotation"):
        return JumpToAnnotation;
    case Hash("ResetArpeggiatorChanges"):
        return ResetArpeggiatorChanges;
    case Hash("ApplyArpeggiator"):
        return ApplyArpeggiator;
    case Hash("InitWorkspace"):
        return InitWorkspace;
    case Hash("RenameInstrument"):
        return RenameInstrument;
    case Hash("UpdateInstrument"):
        return UpdateInstrument;
    case Hash("DeleteInstrument"):
        return DeleteInstrument;
    case Hash("ScanAllPlugins"):
        return ScanAllPlugins;
    case Hash("ScanPluginsFolder"):
        return ScanPluginsFolder;
    case Hash("CreateInstrument"):
        return CreateInstrument;
    case Hash("DeleteTrack"):
        return DeleteTrack;
    case Hash("MuteTrack"):
        return MuteTrack;
    case Hash("UnmuteTrack"):
        return UnmuteTrack;
    case Hash("RenameTrack"):
        return RenameTrack;
    case Hash("SelectTrackColour"):
        return SelectTrackColour;
    case Hash("SelectTrackInstrument"):
        return SelectTrackInstrument;
    case Hash("SelectAllEvents"):
        return SelectAllEvents;
    case Hash("DuplicateTrackTo"):
        return DuplicateTrackTo;
    case Hash("SetTrackColour"):
        return SetTrackColour;
    case Hash("SetTrackInstrument"):
        return SetTrackInstrument;
    case Hash("MoveTrackToProject"):
        return MoveTrackToProject;
    case Hash("DeleteEvents"):
        return DeleteEvents;
    case Hash("CopyEvents"):
        return CopyEvents;
    case Hash("CutEvents"):
        return CutEvents;
    case Hash("PasteEvents"):
        return PasteEvents;
    case Hash("CursorTool"):
        return CursorTool;
    case Hash("DrawTool"):
        return DrawTool;
    case Hash("SelectionTool"):
        return SelectionTool;
    case Hash("ZoomTool"):
        return ZoomTool;
    case Hash("DragTool"):
        return DragTool;
    case Hash("InsertSpaceTool"):
        return InsertSpaceTool;
    case Hash("WipeSpaceTool"):
        return WipeSpaceTool;
    case Hash("ScissorsTool"):
        return ScissorsTool;
    case Hash("ZoomIn"):
        return ZoomIn;
    case Hash("ZoomOut"):
        return ZoomOut;
    case Hash("Undo"):
        return Undo;
    case Hash("Redo"):
        return Redo;
    case Hash("RefactorNotes"):
        return RefactorNotes;
    case Hash("BatchTweakNotes"):
        return BatchTweakNotes;
    case Hash("ArpeggiateNotes"):
        return ArpeggiateNotes;
    case Hash("TweakNotesVolume"):
        return TweakNotesVolume;
    case Hash("ShowAnnotations"):
        return ShowAnnotations;
    case Hash("ResetVolumeChanges"):
        return ResetVolumeChanges;
    case Hash("ApplyOpenGLRenderer"):
        return ApplyOpenGLRenderer;
    case Hash("TransportStartPlayback"):
        return TransportStartPlayback;
    case Hash("TransportPausePlayback"):
        return TransportPausePlayback;
    case Hash("PopupMenuDismiss"):
        return PopupMenuDismiss;
    case Hash("PopupMenuDismissedAsDone"):
        return PopupMenuDismissedAsDone;
    case Hash("PopupMenuDismissedAsCancel"):
        return PopupMenuDismissedAsCancel;
    case Hash("SelectRootItemPanel"):
        return SelectRootItemPanel;
    case Hash("DeselectRootItemPanel"):
        return DeselectRootItemPanel;
    case Hash("UpdateRootItemPanel"):
        return UpdateRootItemPanel;
    case Hash("VersionControlForcePull"):
        return VersionControlForcePull;
    case Hash("VersionControlReset"):
        return VersionControlReset;
    case Hash("VersionControlAmend"):
        return VersionControlAmend;
    case Hash("VersionControlCommit"):
        return VersionControlCommit;
    case Hash("LoginLogout"):
        return LoginLogout;
    case Hash("OpenProject"):
        return OpenProject;
    case Hash("CreateNewProject"):
        return CreateNewProject;
    case Hash("RenderToFLAC"):
        return RenderToFLAC;
    case Hash("RenderToOGG"):
        return RenderToOGG;
    case Hash("RenderToWAV"):
        return RenderToWAV;
    case Hash("AddItemsMenu"):
        return AddItemsMenu;
    case Hash("AddItemsMenuBack"):
        return AddItemsMenuBack;
    case Hash("AddMidiTrack"):
        return AddMidiTrack;
    case Hash("AddMidiTrackConfirmed"):
        return AddMidiTrackConfirmed;
    case Hash("AddAutomationTrack"):
        return AddAutomationTrack;
    case Hash("ImportMidi"):
        return ImportMidi;
    case Hash("ExportMidi"):
        return ExportMidi;
    case Hash("UnloadProject"):
        return UnloadProject;
    case Hash("DeleteProject"):
        return DeleteProject;
    case Hash("DeleteProjectConfirmed1"):
        return DeleteProjectConfirmed1;
    case Hash("DeleteProjectConfirmed2"):
        return DeleteProjectConfirmed2;
    case Hash("RefactorTransposeUp"):
        return RefactorTransposeUp;
    case Hash("RefactorTransposeDown"):
        return RefactorTransposeDown;
    case Hash("RefactorRemoveOverlaps"):
        return RefactorRemoveOverlaps;
    case Hash("ProjectPatternEditor"):
        return ProjectPatternEditor;
    case Hash("ProjectLinearEditor"):
        return ProjectLinearEditor;
    case Hash("ProjectVersionsEditor"):
        return ProjectVersionsEditor;
    case Hash("ProjectMainMenu"):
        return ProjectMainMenu;
    case Hash("ProjectRenderMenu"):
        return ProjectRenderMenu;
    case Hash("ProjectBatchMenu"):
        return ProjectBatchMenu;
    case Hash("ProjectBatchMenuBack"):
        return ProjectBatchMenuBack;
    case Hash("ProjectInstrumentsMenu"):
        return ProjectInstrumentsMenu;
    case Hash("AddTempoController"):
        return AddTempoController;
    case Hash("AddCustomController"):
        return AddCustomController;
    case Hash("BatchChangeInstrument"):
        return BatchChangeInstrument;
    case Hash("BatchSetInstrument"):
        return BatchSetInstrument;
    case Hash("DismissModalDialogAsync"):
        return DismissModalDialogAsync;
    case Hash("SelectFunction"):
        return SelectFunction;
    case Hash("SelectScale"):
        return SelectScale;
    case Hash("SelectTimeSignature"):
        return SelectTimeSignature;
    case Hash("SwitchBetweenRolls"):
        return SwitchBetweenRolls;
    case Hash("ShowPreviousPage"):
        return ShowPreviousPage;
    case Hash("ShowNextPage"):
        return ShowNextPage;
    case Hash("ToggleShowHideConsole"):
        return ToggleShowHideConsole;
    case Hash("ToggleShowHideCombo"):
        return ToggleShowHideCombo;
    case Hash("StartDragViewport"):
        return StartDragViewport;
    case Hash("EndDragViewport"):
        return EndDragViewport;
    case Hash("SelectAudioDeviceType"):
        return SelectAudioDeviceType;
    case Hash("SelectAudioDevice"):
        return SelectAudioDevice;
    case Hash("SelectSampleRate"):
        return SelectSampleRate;
    case Hash("SelectBufferSize"):
        return SelectBufferSize;
    case Hash("EditModeDefault"):
        return EditModeDefault;
    case Hash("EditModeDraw"):
        return EditModeDraw;
    case Hash("EditModePan"):
        return EditModePan;
    case Hash("EditModeWipeSpace"):
        return EditModeWipeSpace;
    case Hash("EditModeInsertSpace"):
        return EditModeInsertSpace;
    case Hash("EditModeSelect"):
        return EditModeSelect;
    case Hash("BeatShiftLeft"):
        return BeatShiftLeft;
    case Hash("BeatShiftRight"):
        return BeatShiftRight;
    case Hash("BarShiftLeft"):
        return BarShiftLeft;
    case Hash("BarShiftRight"):
        return BarShiftRight;
    case Hash("KeyShiftUp"):
        return KeyShiftUp;
    case Hash("KeyShiftDown"):
        return KeyShiftDown;
    case Hash("OctaveShiftUp"):
        return OctaveShiftUp;
    case Hash("OctaveShiftDown"):
        return OctaveShiftDown;
    case Hash("CleanupOverlaps"):
        return CleanupOverlaps;
    case Hash("InvertChordUp"):
        return InvertChordUp;
    case Hash("InvertChordDown"):
        return InvertChordDown;
    case Hash("ToggleQuickStash"):
        return ToggleQuickStash;
    case Hash("ShowArpeggiatorsPanel"):
        return ShowArpeggiatorsPanel;
    case Hash("ShowVolumePanel"):
        return ShowVolumePanel;
    case Hash("TweakVolumeRandom"):
        return TweakVolumeRandom;
    case Hash("TweakVolumeFadeOut"):
        return TweakVolumeFadeOut;
    case Hash("CreateArpeggiatorFromSelection"):
        return CreateArpeggiatorFromSelection;
    default:
        return 0;
    };
}
