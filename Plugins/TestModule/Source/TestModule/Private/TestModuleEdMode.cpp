// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestModuleEdMode.h"
#include "TestModuleEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FTestModuleEdMode::EM_TestModuleEdModeId = TEXT("EM_TestModuleEdMode");

FTestModuleEdMode::FTestModuleEdMode()
{

}

FTestModuleEdMode::~FTestModuleEdMode()
{

}

void FTestModuleEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FTestModuleEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FTestModuleEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FTestModuleEdMode::UsesToolkits() const
{
	return true;
}




