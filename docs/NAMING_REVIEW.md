# Names to review

Generated from `tools/resolve_names.py` (2026-10-31). Every name below is written in the sources and now has its
address checked (symbol_addrs.txt), but it was chosen while matching and is not confirmed by Sly 1. Confirm or fix
each one; a confirmed name can then replace the `func_` name with `tools/rename.py --merge-used`.

## Names used in the sources for a `func_` address (280)

The matcher who wrote the caller named the callee; the callee itself is still `func_`. Registered as aliases only.

| Address | Name used by callers |
|---|---|
| 0x117120 | `HermiteVec4__FfffUxUxUxUxP7VECTOR4N27` |
| 0x118458 | `ReadFileRecord__18CBinaryInputStreamPv` |
| 0x119090 | `PbspPointInBsp__FP3BSPT0Ux` |
| 0x11A050 | `InitSl__FP2SLi` |
| 0x11A070 | `AppendSlEntry__FP2SLPv` |
| 0x11B340 | `InvertMatrix3__FP7MATRIX3` |
| 0x11C318 | `MatInvertMat4__FP7MATRIX4` |
| 0x11E1A0 | `MakeVecFromAngle` |
| 0x11E208 | `VuvecSphere` |
| 0x127B70 | `RemoveParent__6CFrameP6CFrame` |
| 0x1296A8 | `SetVector4__4CRefPC7VECTOR4` |
| 0x129718 | `SetVector4__4CRefUx` |
| 0x129D58 | `RefCoerceS32__C4CRef` |
| 0x129DA8 | `RefCoerceF32__C4CRef` |
| 0x12A0B0 | `InitTag__4CRefi` |
| 0x12D058 | `FFindInOwnerChain__FP3ACT` |
| 0x12DA30 | `SetAct1ValueKeepOffset__FP4ACT1Ux` |
| 0x12E0F0 | `SetGoal__4ACT8UxUx` |
| 0x12FE58 | `FindAsegChannelTarget__FP4ASEGP3ALOP3CHNPP2SOPP2XF` |
| 0x131968 | `FAsegaStopped__FP5ASEGA` |
| 0x1333C0 | `AddRefOidRef` |
| 0x133448 | `ReleaseRefNode` |
| 0x1371C8 | `JtInteractPre__FP5JTREC` |
| 0x1374F0 | `NJtRecSide__FP5JTREC` |
| 0x1375D0 | `SetJtRecState__FP5JTRECi` |
| 0x13E590 | `PostLoadOidField__FP2LOPv` |
| 0x13E5E0 | `PostLoadOidSetter__FP2LOPv` |
| 0x13E690 | `RefFromBrx__F4OTYPP18CBinaryInputStream` |
| 0x13FAD0 | `FIsLoadFilterMatch__FiPs` |
| 0x140AF8 | `FFightStanceInRange` |
| 0x140C88 | `SetPlayerTn__FP10STEPPLAYERP2TN` |
| 0x141968 | `LaunchJtToPos` |
| 0x141CD0 | `PayGadgetCost__FP10STEPPLAYERi` |
| 0x141EA8 | `GrfMatchingSlots` |
| 0x142140 | `StepCmdHoldOn__FP10STEPPLAYERP2LO` |
| 0x1421A0 | `StepCmdCarry__FP10STEPPLAYERP2LO` |
| 0x1421F8 | `StepCmdPlaceHeld__FP10STEPPLAYERP2LO` |
| 0x142278 | `StepCmdPutDown__FP10STEPPLAYERP2LOT1` |
| 0x142340 | `StepCmdHoldOn9__FP10STEPPLAYERP2LO` |
| 0x1423A0 | `FStepHoldArrived__FP10STEPPLAYER` |
| 0x1424C0 | `FStepPutDownDone__FP10STEPPLAYER` |
| 0x1424D0 | `FStepHoldOn9Done__FP10STEPPLAYER` |
| 0x1424E0 | `StepCmdGrab0xC__FP10STEPPLAYERP4ASEGP2LOi` |
| 0x142530 | `FStepGrab0xCDone__FP10STEPPLAYER` |
| 0x142868 | `ClearHeroIdleTimer` |
| 0x142880 | `RollHeroIdleTimer` |
| 0x1430C8 | `GrfJtLeanMask` |
| 0x143D20 | `FJtLandsWithin__FfP4STEP` |
| 0x143EE0 | `PlayStepClip__FP10STEPPLAYER3OIDii` |
| 0x143FF8 | `StopStepClip__FP10STEPPLAYER` |
| 0x144038 | `FStepClipPlaying__FP10STEPPLAYER` |
| 0x1441A0 | `GetHeroMp` |
| 0x1443D8 | `FJtModeActive__FP10STEPPLAYER` |
| 0x1448F0 | `SetJtGoalPos__FP6JTGOALUx` |
| 0x144EE8 | `FBhv193AtGoal__FP6BHV193` |
| 0x144F48 | `SetBhv193Goal__FP6BHV193Ux` |
| 0x14D8C0 | `CutCm__FP2CM` |
| 0x14DC58 | `RecalcCm__FP2CM` |
| 0x14E078 | `UpdateCmVisZone__FP2CM` |
| 0x14E1A8 | `SetCmPanTilt__FP2CMUxUxff` |
| 0x14E270 | `CalcRecipFitParams__FfP2CMPf` |
| 0x14E328 | `PushHeroCameraMode__FP2CMiPvii` |
| 0x14E4C8 | `PopHeroCameraMode` |
| 0x14F110 | `ClipCmEye__FP2CMUxUx` |
| 0x14FD50 | `FIsTop__5CPLCY` |
| 0x150E20 | `SetOwner__6CPZOOMP2LO` |
| 0x150E60 | `SetFocus__6CPZOOMP2LO` |
| 0x150EA0 | `SetPose__6CPZOOMUxUxf` |
| 0x150EE8 | `SetZoom__6CPZOOMf` |
| 0x150F58 | `FAtTargetFocus__6CPZOOM` |
| 0x151018 | `FAtTargetEye__6CPZOOM` |
| 0x1510D8 | `FAtTargetZoom__6CPZOOM` |
| 0x1524A0 | `PlayJtAsegDefault` |
| 0x15F8A8 | `PglyphFromCh__8CFontBrxUc` |
| 0x1604E8 | `UpdateXflock__FP2SOP6XFLOCK` |
| 0x1619A0 | `OnGameEvent__FP4GAMEiP2LO` |
| 0x161F48 | `SetTaskStates__FP4GAMEiP8TASKPAIRP2LO` |
| 0x167870 | `LoadPoseSetsFromBrx__FP7GLOBSETP18CBinaryInputStream` |
| 0x169988 | `CompareVertRec__FPCvT0` |
| 0x1699E8 | `LoadSubglobInstancesFromBrx__FP7GLOBSETP7SUBGLOBP4GLOBP8SUBGLOBXiiPiPP5BATCHP18CBinaryInputStream` |
| 0x169EB8 | `CopyDmaRefsChainSw__FP7SUBGLOBP4GLOBiPviPcT5` |
| 0x16A000 | `LoadSubglobType0FromBrx` |
| 0x16C8E0 | `LoadClutSetFromBrx__FP7GLOBSETP18CBinaryInputStream` |
| 0x16CAA0 | `LoadSubglobCelFromBrx__FP7GLOBSETP7SUBGLOBP4GLOBP11SUBGLOBLOADP8SUBGLOBXiP18CBinaryInputStream` |
| 0x16CF78 | `LoadSubglobType3FromBrx__FP7GLOBSETP7SUBGLOBP4GLOBP11SUBGLOBLOADP8SUBGLOBXiP18CBinaryInputStream` |
| 0x16E438 | `LoadSubglobCelNoShdFromBrx__FP7GLOBSETP7SUBGLOBP4GLOBP11SUBGLOBLOADP8SUBGLOBXiP18CBinaryInputStream` |
| 0x171CF8 | `SetStepSsgGoal__FP4STEPP3SSG` |
| 0x171D58 | `ResetStepGoal__FP4STEPP3SSG` |
| 0x171DA8 | `FStepGoalIs__FP4STEPP3SSG` |
| 0x173610 | `GuardSpawnerGroundSnap` |
| 0x178D00 | `FBhv166NearEnd__FP6BHV166` |
| 0x178D90 | `SetBhv166Path__FP6BHV166Pvi` |
| 0x184670 | `PspotFromLo__FP2LO` |
| 0x185310 | `FindClosestPoint__9CLIMBSURFUxP7SURFLOCT2PUxT4` |
| 0x187DE0 | `LatchButtonEdges__FP3JOYUi` |
| 0x18C120 | `SetJtChannelMask__FP2JTUi` |
| 0x18D6F8 | `FindJtPocket__FP2JTi` |
| 0x18DF50 | `SetJtUnk1d30` |
| 0x18E1E0 | `UpdateJtPounceArc` |
| 0x18E540 | `SetJtAnimState` |
| 0x18E540 | `SetJtAnimState__FP2JTi` |
| 0x190BE0 | `JtHangFrame` |
| 0x190E18 | `UpdateJtHangPlace` |
| 0x1911A8 | `UpdateJtGrabPre` |
| 0x1928F8 | `EnterJtGrabState` |
| 0x192BD8 | `SetJtGrabPhase` |
| 0x1938C0 | `ChooseJtGrabTarget__FP6JTGRABUii` |
| 0x194558 | `FJtgrabCanUseGadget__FP6JTGRABi` |
| 0x194688 | `AddJtGrabCandidate__FP2SWP10STEPPLAYERUxP2LOP8GRABSPOTiP10JTGRABCAND` |
| 0x194F70 | `UpdateJtGrabCandidates__FP2SWP10STEPPLAYERiP10JTGRABCAND` |
| 0x195368 | `EmitJtGrabSparkles__FP2SWP10STEPPLAYERiP10JTGRABCAND` |
| 0x195A00 | `SetJtAirJump__FP5JTAIRiiP2LO` |
| 0x195FB8 | `SetJtAirState__FP5JTAIRiP2LO` |
| 0x197370 | `SteerJtAirClip__FP5JTAIR` |
| 0x1974C8 | `PxpFirstOfTree__FP6SOTREE` |
| 0x199D48 | `FindJtEdgeGrabContact` |
| 0x19A098 | `FJtAirWedged__FfP10STEPPLAYERPf` |
| 0x19A750 | `JtPlanLaunchVz__FP5JTAIRi` |
| 0x19B110 | `TryJtAirGrab__FP5JTAIRP2LO` |
| 0x19C688 | `StartJtGrabForAirKind` |
| 0x19C828 | `ReleaseJtAirObject__FP5JTAIR` |
| 0x19C8D0 | `FJtairCanUseGadget__FP5JTAIRi` |
| 0x19CC50 | `StartJtMode__FP6JTMODEiP4STEPP2LO` |
| 0x19CD38 | `SetJtModeState__FP6JTMODEi` |
| 0x19D660 | `SetState__9JTMODEHUDi` |
| 0x19DCA0 | `SetWidgetCur__9JTMODEHUDP6WIDGET` |
| 0x19E110 | `GetJtPipeLimits__FP6JTPIPEPf` |
| 0x19E1E0 | `UpdateJtPipe__FP6JTPIPE` |
| 0x19EAB0 | `SetJtPipeState__FP6JTPIPEi` |
| 0x19EEF0 | `FJtpipeCanUseGadget__FP6JTPIPEi` |
| 0x19F3F8 | `QwPosOfJtPlace` |
| 0x19F590 | `RespawnAtSafeSpot` |
| 0x1A0B40 | `SetHeroHurtState` |
| 0x1A12F0 | `HeroHurtPre__FP6JTHURT` |
| 0x1A5D58 | `AddLoRunListEntry__FP2LO` |
| 0x1A6290 | `FObjHasTarget` |
| 0x1A62E8 | `PosLoWorld__FP2LO` |
| 0x1A6318 | `PmatLoWorld__FP2LO` |
| 0x1A6730 | `Clone__2LOP2LO` |
| 0x1A6D28 | `SetLoVisMask__FP2LOUi` |
| 0x1A6F00 | `ConvertLoPos__FP2LOT0Ux` |
| 0x1A6FC0 | `XfmVecLoWorld__FP2LOT0Ux` |
| 0x1A9108 | `ContactInsideBsp__FfP3BSPT1P4GEOMUxP9CMCONTACT` |
| 0x1AE478 | `FrameInit` |
| 0x1AE478 | `__10STACKSCOPE` |
| 0x1AE478 | `__3CLS` |
| 0x1AE478 | `__3CTX` |
| 0x1AE478 | `__3OBJ` |
| 0x1AE478 | `__4MARK` |
| 0x1AE478 | `__5FRAME` |
| 0x1AE478 | `__6CFrame` |
| 0x1C40C0 | `FIsSwHero` |
| 0x1C4660 | `GrfPressedWithin__5POCTLUif` |
| 0x1C46C0 | `GrfConsumePressed__5POCTLUif` |
| 0x1C4700 | `FConsumePressed__5POCTLUi` |
| 0x1C4738 | `ClearJoyPressed__5POCTLi` |
| 0x1C9940 | `IdProxy__Fii` |
| 0x1C9950 | `IsrcFromIdProxy__Fi` |
| 0x1C99D8 | `FindPxr__FP3PXRiPi` |
| 0x1CA370 | `AddProxyCopy__FP2SWiP2SOP2XF3OIDP7MATRIX4P14CLoadCollector` |
| 0x1CA930 | `IcopyFromPspare__FP5PROXYP10PROXYSPARE` |
| 0x1CADE0 | `PspareChoose__FP5PROXYi` |
| 0x1CB2C0 | `FCanAcquireProxy__FP5PROXY` |
| 0x1CB658 | `PproxyFromLo__FP2LO` |
| 0x1CB770 | `FindProxysrc__FP2SWi` |
| 0x1D6848 | `CalculateLaunchVelocity` |
| 0x1D88D0 | `PsvpMake__FPCce` |
| 0x1D8B20 | `SetSaveVarByName__FRC4CRefPCce` |
| 0x1DA4B8 | `SetHintBoxText` |
| 0x1DA578 | `ClearIfSlotId` |
| 0x1DA5B0 | `GetHintBoxTextId` |
| 0x1DAEA8 | `FPowerUpAcquired` |
| 0x1DFD58 | `RelayFire` |
| 0x1E0070 | `RemoveRelayAlarm__FP5RELAYP5ALARM` |
| 0x1E0180 | `PjsgFindRelayBlock__FP5RELAY3OIDP3JSG` |
| 0x1E1C40 | `UpdateJsg__FP3JSG` |
| 0x1E1DB8 | `PloFindJsgObject__FP3JSG3OID` |
| 0x1E4530 | `DtJsgCommand__FP3JSGP8RELAYCMD` |
| 0x1E4EB8 | `SetJsgJt__FP3JSGP8RELAYCMDP2LO` |
| 0x1E50E0 | `SetJsgHandsOff__FP3JSGii` |
| 0x1E5410 | `ReleaseJsgSma__FP3JSG` |
| 0x1E54B0 | `EndJsgJtMode__FP3JSG` |
| 0x1E5628 | `EndJsg__FP3JSG` |
| 0x1E57A0 | `StartJsgCamBlend__FP3JSGP8RELAYCMDT1f` |
| 0x1E5A98 | `PopJsgCamBlend__FP3JSGi` |
| 0x1E5AE0 | `PjsgStartBlock__FP5RELAYP8RELAYCMDP3JSG` |
| 0x1E6620 | `PeekFirstB` |
| 0x1E6648 | `PeekLastB` |
| 0x1E67B8 | `GetShapePosDirAtU__FP5SHAPEfPUxT2` |
| 0x1E6F10 | `GetShapePosDirAtS__FP5SHAPEfPUxT2` |
| 0x1E6F60 | `FindShapeClosestPointAll__FP5SHAPEUxP6CONSTRPUxP7VECTOR4PfT5` |
| 0x1EC688 | `AddVifUnpackShdp__FP3SHDiiP4VIFS` |
| 0x1EC820 | `PshdFromOid` |
| 0x1EC8F8 | `PshdFromIshd__Fi` |
| 0x1ED278 | `FixupRgba__FP4RGBA` |
| 0x1EECD0 | `ClearBhvstk` |
| 0x1F0638 | `FIsSmaRetracted__FP3SMA` |
| 0x1F2A60 | `ShowSoPartRec__FP2SOP6SOPART` |
| 0x1F4E28 | `ClearSoXps__FP2SO` |
| 0x1F67E0 | `PsmaFindOnAlo__FP3ALO3OID` |
| 0x1FA810 | `QwApplyConstrInXf` |
| 0x1FAC30 | `AddSoVelocity__FP2SOUx` |
| 0x1FB1F8 | `SetSndVolume__FP3SNDf` |
| 0x1FB2F8 | `SetSndOwner__FP3SNDP2LO` |
| 0x1FB4F0 | `SetSndNearFar__FP3SNDff` |
| 0x1FBB90 | `MakeSnd__Fi` |
| 0x1FCCF0 | `__nw__1XUi` |
| 0x1FE150 | `StartMusic` |
| 0x1FE310 | `StopMusic` |
| 0x1FE3F8 | `GetFirstTimerSeconds` |
| 0x1FE5F0 | `StartDialogueLine` |
| 0x1FE848 | `FCurrentIdMatches` |
| 0x1FEA60 | `SetSoundBusVolume__FP6SNDMGRifi` |
| 0x204660 | `SetStepRadTarget__FP4STEPf` |
| 0x2046B0 | `SetStepRadTowardDir__FP4STEPUx` |
| 0x204CA8 | `UpdateHeadingSmooth` |
| 0x205438 | `PbhvPushStep` |
| 0x205458 | `PbhvFindStep` |
| 0x209EE0 | `GuardCapVelocityForPounce` |
| 0x20BD68 | `ClearGaitFootDown` |
| 0x20F0C0 | `IncrementSwNoPause__FP2SW` |
| 0x20F0F0 | `DecrementSwNoPause__FP2SW` |
| 0x210338 | `FadeAsegObjectEvent__FP2SWi3OIDfP2LOP4ASEG` |
| 0x210408 | `SetAsegPartFlagEvent__FP2SWi3OIDT2P2LOT4P4ASEG` |
| 0x2104A0 | `ShowAsegPartEvent__FP2SWi3OIDT2P2LOT4P4ASEG` |
| 0x210538 | `ExplodeAsegEvent__FP2SW3OIDN21P2LOP4ASEGf` |
| 0x210678 | `SetAsegEyesEvent__FP2SW3OIDT1P2LOP4ASEGf` |
| 0x210740 | `PlayAsegSoundEvent__FP2SWi3OIDiifffP2LOT8P4ASEGPt7CRefPtr1Z3SND` |
| 0x2108E8 | `StopAsegSoundEvent__FP2SWiP4ASEGPt7CRefPtr1Z3SND` |
| 0x210A88 | `GetCurrentJob__Fv` |
| 0x210B28 | `NGetEpisodeBest__Fv` |
| 0x21CB18 | `UpdateChainLink__FP2SOP9CHAINLINK` |
| 0x21F418 | `UpdateJtThrow__FP7JTTHROW` |
| 0x2206C8 | `SetJtThrowState` |
| 0x220DD8 | `CalcCpdFocus__FP3CPDP6CPDEFIPUxP2TN` |
| 0x221CE8 | `UpdateCmProgress__FP7CMPART2P6CPDEFI` |
| 0x2236E8 | `UpdateCmLineOfSight__FP7CMPART2` |
| 0x223A70 | `FreeCamClip__FP7CMPART2UxUxPUx` |
| 0x224590 | `FPocketItemCarried__FP6CID100` |
| 0x227788 | `ClearSubtitle__FP8SUBTITLE` |
| 0x228170 | `PutSwHeroAtWarp__FP4WARP` |
| 0x22C8C0 | `SlotStoreValue__FP2XFUx` |
| 0x22CA18 | `SlotRestValue__FP2XFP7MATRIX4` |
| 0x22CAD0 | `QwRotRateFromEulerRate__FUxUx` |
| 0x22D148 | `MatDmatOfXfChain__FP2XFT0` |
| 0x22D670 | `PushXf__FP2XF` |
| 0x22D698 | `PopXf__FP2XF` |
| 0x22D6B0 | `PxfFromIxf__FiP2SOT1` |
| 0x22DD00 | `SlotRefresh__FP2SOP2XF` |
| 0x22FC48 | `ConvertXfPos__FP2XFT0Ux` |
| 0x230018 | `InsertNodeBySlot__FP2SOP2XFP3ACT` |
| 0x230100 | `RemoveNodeBySlot__FP2SOP2XFP3ACT` |
| 0x2303A0 | `SlotSetRole__FP2SOP2XFi` |
| 0x2313F0 | `InvalidateXfmWorld__FP3XFM` |
| 0x234580 | `strtol` |
| 0x234620 | `SetGsCrt` |
| 0x234740 | `AddDmacHandler` |
| 0x234750 | `RemoveDmacHandler` |
| 0x234A50 | `iSignalSema` |
| 0x234D60 | `sceGsPutIMR` |
| 0x234E30 | `sceSifGetReg` |
| 0x234E50 | `Deci2Call` |
| 0x234E80 | `GetMemorySize` |
| 0x234E90 | `_InitTLB` |
| 0x2351E0 | `DisableDmac` |
| 0x235248 | `EnableDmac` |
| 0x2394A0 | `EI` |
| 0x2394A0 | `EIntr` |
| 0x23EB40 | `__unwinding_cleanup` |
| 0x2401D8 | `strcmp` |
| 0x240328 | `abort` |
| 0x2405F0 | `sceGsGetGParam` |
| 0x24B920 | `_sceMpegHeapInit` |
| 0x24B930 | `_sceMpegHeapAlloc` |
| 0x256120 | `Unlink__t6CGcObj1Z7CMethod` |
| 0x256C58 | `Assign__3SPNP4NODE` |
| 0x256EE0 | `__as__t7CRefPtr1Z6CFrameP6CFrame` |
| 0x257148 | `_$_3O20` |
| 0x258200 | `SetSaveVar__FP6SVPATHRC4CRefP8SAVEDATA` |
| 0x259CF8 | `Attach__t7CRefPtr1Z7CMethodP7CMethod` |

## Names that contradict the existing name of their address (40)

Different callers (or config) use unrelated names for the same function; at most one is right.

| Address | Name used by callers | Name in functions.csv |
|---|---|---|
| 0x11C1A8 | `__ml__FRC2M4G10VU_VECTOR4` | `__ml__FRC7MATRIX4G10VU_VECTOR4` |
| 0x11C448 | `BuildProj__FPvffffff` | `BuildSimpleProjectionMatrix__FffffffP7MATRIX4` |
| 0x1291E0 | `__4CRefPCx` | `__4CRefPC6VECTOR` |
| 0x129518 | `SetS32__4CRefi` | `__as__4CRefi` |
| 0x129558 | `SetF32__4CReff` | `__as__4CReff` |
| 0x129598 | `SetBool__4CRefi` | `__as__4CRefb` |
| 0x1296A8 | `__as__4CRefRC6VECTOR` | `__as__4CRefPx` |
| 0x129808 | `__as__4CRefRC4QW16` | `SetClq__4CRefP3CLQ` |
| 0x129878 | `__as__4CRefRC2V2` | `SetLm__4CRefP2LM` |
| 0x1298F0 | `__as__4CRefRC2V3` | `SetSmp__4CRefP3SMP` |
| 0x129A10 | `SetBasic__4CRefP5BASIC` | `__as__4CRefPv` |
| 0x129A10 | `__as__4CRefP1O` | `__as__4CRefPv` |
| 0x129A10 | `__as__4CRefP2LO` | `__as__4CRefPv` |
| 0x129A10 | `__as__4CRefP3T18` | `__as__4CRefPv` |
| 0x1305B8 | `PlayJtAseg__FP4ASEGP3ALOffiPP5ASEGA` | `ApplyAsegCur__FP4ASEGP3ALOffiPP5ASEGA` |
| 0x1576B0 | `EndDmaCnt__4GIFS` | `AddDmaEnd__4DMAS` |
| 0x1AE4A0 | `FrameFree` | `_$_18CBinaryInputStream` |
| 0x1AE4A0 | `_$_10STACKSCOPE` | `_$_18CBinaryInputStream` |
| 0x1AE4A0 | `_$_3CLS` | `_$_18CBinaryInputStream` |
| 0x1AE4A0 | `_$_3CTX` | `_$_18CBinaryInputStream` |
| 0x1AE4A0 | `_$_4MARK` | `_$_18CBinaryInputStream` |
| 0x1AE4A0 | `_$_6CFrame` | `_$_18CBinaryInputStream` |
| 0x1E00E8 | `FRelayHasAlarm__FP5RELAYP5ALARM` | `FWipingAseg__FP4ASEG` |
| 0x21EDA0 | `strcat` | `strcpy1` |
| 0x21EE30 | `strupr` | `UpperizePchz__FPc` |
| 0x236918 | `sceVsnprintf` | `sceSnprintf` |
| 0x238F38 | `_sceSifLoadModule` | `_sceSifLoadModuleBuffer` |
| 0x239450 | `DI` | `DIntr` |
| 0x23A920 | `sceSifSetReg` | `sceSifExecNotifyHandler` |
| 0x24FA38 | `_sceMpegErr` | `_sceMpegError` |
| 0x252148 | `_getBits` | `_sceMpegNextBit` |
| 0x2564B8 | `__8VU_QWORD` | `__3VUF` |
| 0x256C58 | `__as__2SPP4NODE` | `__as__3SPMP4NODE` |
| 0x256C58 | `__as__3SPNP4NODE` | `__as__3SPMP4NODE` |
| 0x256C58 | `__as__3SPYP1Y` | `__as__3SPMP4NODE` |
| 0x256CE8 | `__10VU_FLOAT_Xf` | `__8VU_FLOATf` |
| 0x256D28 | `__ml__FG10VU_FLOAT_XG9VU_VECTOR` | `__ml__FG8VU_FLOATG9VU_VECTOR` |
| 0x256EE0 | `__as__3SPFP5FRAME` | `__as__3SPXP1X` |
| 0x256EE0 | `__as__3SPZP1Z` | `__as__3SPXP1X` |
| 0x257450 | `__as__3SPBP7BINDING` | `__as__3SPMP7BINDING` |

## Names used for several addresses (10)

Local stand-in classes (`X`, `Y`, `O`…) reused with different meanings, or two copies of a library table.

| Name | Addresses (uses) |
|---|---|
| `DisableIntc` | 0x235110 (1), 0x2351E0 (1) |
| `RemoveIntcHandler` | 0x234720 (1), 0x234750 (1) |
| `Set__3SPOP1O` | 0x257038 (3), 0x257058 (2) |
| `Set__3SPWP1W` | 0x256C38 (2), 0x257430 (2) |
| `_$_1O` | 0x257148 (3), 0x257078 (1) |
| `_$_3OBJ` | 0x1AE4A0 (5), 0x184950 (1) |
| `_$_3SPM` | 0x256D40 (46), 0x257250 (7) |
| `_$_5FRAME` | 0x1AE4A0 (32), 0x257078 (2) |
| `__as__3SPMP1W` | 0x257450 (2), 0x256C58 (1) |
| `__as__4CRefP3OBJ` | 0x1299C0 (1), 0x129618 (1) |

Also kept as `func_` on purpose: `func_001A7518` (the game's `main`; gcc compiles a function named `main`
differently) and `func_001AE478` (STACKSCOPE constructor: sources declare local classes whose inline constructors
compile to the candidate names `__5FRAME` / `__10STACKSCOPE`, so renaming makes them call themselves).
