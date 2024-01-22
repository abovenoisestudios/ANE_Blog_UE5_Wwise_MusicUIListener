// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyUEProject : ModuleRules
{
	public MyUEProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject",
			"Engine", "InputCore", "EnhancedInput", "AkAudio", "WwiseSoundEngine"});
		
		if (Target.bBuildEditor)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
		}
	}
}
