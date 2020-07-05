// Fill out your copyright notice in the Description page of Project Settings.


#include "TextAssetFactory.h"
#include "TextAsset.h"
#include "TextAssetTypeActions.h"
#include <IAssetTools.h>
#include <Modules/ModuleManager.h>

UTextAssetFactory::UTextAssetFactory() //:Super()
{
	//IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	//RegisterAssetTypeAction(AssetTools, MakeShareable(new FTextAssetTypeActions()));

	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UTextAsset::StaticClass();
}

UObject* UTextAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	auto MyTextAsset = NewObject<UTextAsset>(InParent, InClass, InName, Flags);
	return MyTextAsset;
}

