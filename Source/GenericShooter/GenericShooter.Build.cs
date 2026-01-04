// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GenericShooter : ModuleRules
{
	public GenericShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"GenericShooter",
			"GenericShooter/Variant_Platforming",
			"GenericShooter/Variant_Platforming/Animation",
			"GenericShooter/Variant_Combat",
			"GenericShooter/Variant_Combat/AI",
			"GenericShooter/Variant_Combat/Animation",
			"GenericShooter/Variant_Combat/Gameplay",
			"GenericShooter/Variant_Combat/Interfaces",
			"GenericShooter/Variant_Combat/UI",
			"GenericShooter/Variant_SideScrolling",
			"GenericShooter/Variant_SideScrolling/AI",
			"GenericShooter/Variant_SideScrolling/Gameplay",
			"GenericShooter/Variant_SideScrolling/Interfaces",
			"GenericShooter/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
