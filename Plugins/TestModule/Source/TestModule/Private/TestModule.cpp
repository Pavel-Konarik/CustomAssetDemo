// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestModule.h"
#include "TestModuleEdMode.h"
#include <IAssetTools.h>
#include <AssetToolsModule.h>
#include <TextAssetTypeActions.h>

#define LOCTEXT_NAMESPACE "FTestModuleModule"

void FTestModuleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FTestModuleEdMode>(FTestModuleEdMode::EM_TestModuleEdModeId, LOCTEXT("TestModuleEdModeName", "TestModuleEdMode"), FSlateIcon(), true);


	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	EAssetTypeCategories::Type gameAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("JsonEditor")), FText::FromName(TEXT("JsonEditor")));

	TSharedPtr<IAssetTypeActions> actionType = MakeShareable(new FTextAssetTypeActions(gameAssetCategory));

	AssetTools.RegisterAssetTypeActions(actionType.ToSharedRef());

}

void FTestModuleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FTestModuleEdMode::EM_TestModuleEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestModuleModule, TestModule)