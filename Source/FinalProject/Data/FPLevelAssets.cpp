// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/FPLevelAssets.h"
#include "FPLogChannels.h"

const UStaticMesh* UFPLevelAssets::FindMeshesByTag(const FGameplayTag& InputTag) const
{
    for (const FPAssetMeshes& Meshes : AssetMeshes)
	{
		if (Meshes.Mesh && Meshes.InputTag == InputTag)
		{
			return Meshes.Mesh;
		}
	}

	UE_LOG(LogFP, Error, TEXT("Can't find AssetMeshes for InputTag [%s]"), *InputTag.ToString());

	return nullptr;
}

const UMaterial* UFPLevelAssets::FindMaterialsByTag(const FGameplayTag& InputTag) const
{
	for (const FPAssetMaterials& Material : AssetMaterials)
	{
		if (Material.Material && Material.InputTag == InputTag)
		{
			return Material.Material;
		}
	}

	UE_LOG(LogFP, Error, TEXT("Can't find AssetMaterials for InputTag [%s]"), *InputTag.ToString());

	return nullptr;
}

const UParticleSystem* UFPLevelAssets::FindParticlesByTag(const FGameplayTag& InputTag) const
{
	for (const FPAssetParticles& Particles : AssetParticles)
	{
		if (Particles.Particle && Particles.InputTag == InputTag)
		{
			return Particles.Particle;
		}
	}

	UE_LOG(LogFP, Error, TEXT("Can't find AssetParticles for InputTag [%s]"), *InputTag.ToString());

	return nullptr;
}
