#pragma once
#ifdef ATLAS
#include "API\Atlas\Atlas.h"
#pragma comment(lib, "AtlasApi.lib")
#else
#include "API\ARK\Ark.h"
#pragma comment(lib, "ArkApi.lib")
#endif
#include "VoteRewardsConfig.h"
#include <random>
#include "Requests.h"

struct VoteSiteConfig
{
	std::string Site;
	std::string Response;
	bool ExactMatch;
};
const int TotalVoteSites = 2;
#ifdef ATLAS
const std::vector<VoteSiteConfig> VoteSites{ 
	VoteSiteConfig{"atlasserverslist.com", "Success", false},
	VoteSiteConfig{"trackyserver.com", "1", true} };
#else
#include "API\ARK\Ark.h"
#pragma comment(lib, "ArkApi.lib")
const std::vector<VoteSiteConfg> VoteSites{
	VoteSiteConfg{"ark-servers.net", "1", true},
	VoteSiteConfig{"trackyserver.com", "1", true} };
#endif

struct PlayerDataS
{
	long double NextVoteTime[TotalVoteSites];
	bool HasRewarded;
};
std::map<int64, PlayerDataS> PlayerData;


const int GetVoteSiteIndex(const std::string& VoteSite)
{
	for (int i = 0; i < VoteSites.size(); i++) if (VoteSites[i].Site == VoteSite) return i;
	return -1;
}

int RandomNumber(int min, int max)
{
	std::default_random_engine generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(min, max);
	int rnd = distribution(generator);
	return rnd;
}