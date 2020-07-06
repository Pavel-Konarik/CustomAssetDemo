// Fill out your copyright notice in the Description page of Project Settings.


#include "TextAssetTypeActions.h"

FTextAssetTypeActions::FTextAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
	: MyAssetCategory(InAssetCategory)
{
}

FColor FTextAssetTypeActions::GetTypeColor() const
{
	return FColor::Red;
}

void FTextAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects);
}
