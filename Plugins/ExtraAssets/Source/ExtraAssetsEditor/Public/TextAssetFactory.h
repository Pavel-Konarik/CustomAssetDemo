// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "TextAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class EXTRAASSETSEDITOR_API UTextAssetFactory : public UFactory
{
	GENERATED_BODY()
		
public:
	UTextAssetFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)override;
	

};
