// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtraAssetsEditor.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "TextAssetTypeActions.h"

#define LOCTEXT_NAMESPACE "FExtraAssetsEditorModule"

void FExtraAssetsEditorModule::StartupModule()
{
	
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	EAssetTypeCategories::Type gameAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("CustomCategory")), FText::FromName(TEXT("CustomCategory")));

	TSharedPtr<IAssetTypeActions> actionType = MakeShareable(new FTextAssetTypeActions(gameAssetCategory));

	AssetTools.RegisterAssetTypeActions(actionType.ToSharedRef());
	
}

void FExtraAssetsEditorModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FExtraAssetsEditorModule, ExtraAssetsEditor)