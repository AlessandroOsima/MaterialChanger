// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class VRMaterialChanger : ModuleRules
	{
		public VRMaterialChanger(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
                    "VRMaterialChangerPlugin/Public"
                }
				);

			PrivateIncludePaths.AddRange(
				new string[] {
                    "VRMaterialChangerPlugin/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
                    "CoreUObject",
                    "Engine",
                    "InputCore",
                    "Slate",
                    "HeadMountedDisplay",
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
		}
	}
}