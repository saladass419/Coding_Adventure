#include "memtrace.h"
#include "DerivedSymbols.h"

std::string Symbol_Flower::getAbility() {
	return "Flower";
}
std::string Symbol_Wine::getAbility() {
	return "Wine";
}
std::string Symbol_Dog::getAbility() {
	return "Dog";
}
std::string Symbol_Bee::getAbility() {
	return "Bee: Adjacent 'Flower' gain 2x money, gains 2$ for every adjacent 'Flower'";
}
std::string Symbol_Sun::getAbility() {
	return "Sun: Adjacent 'Flower' gain 5x money, gains 3$ for every adjacent 'Flower'";
}
std::string Symbol_BeeHive::getAbility() {
	return "BeeHive: Has a 10% chance to add a 'Bee'";
}
std::string Symbol_Rain::getAbility() {
	return "Rain: Destroys itself after 3 spins, adjacent 'Flower' gain 3x money, has a 5% chance to add a 'Flower'";
}
std::string Symbol_Drunk::getAbility() {
	return "Drunk: Adjacent 'Wine' and 'FineWine' gain 2x money, gains 3$ for every adjacent 'Wine' and 'FineWine', destroys adjacent 'Wine' and 'FineWine', ";
}
std::string Symbol_Bartender::getAbility() {
	return "Bartender: Has a 15% chance to add a 'Wine'";
}
std::string Symbol_Grape::getAbility() {
	return "Grape: Has a 5% chance to turn into 'FineWine', has a 10% chance to turn into 'Wine'";
}
std::string Symbol_FineWine::getAbility() {
    return "FineWine: Has a 20% chance to gain additional 5$";
}
std::string Symbol_Sommelier::getAbility() {
    return "Sommelier: Gains 1$ for every adjacent 'Wine', gains 20$ for every adjacent 'FineWine', adjacent 'FineWine' gain 2x money, destroys adjacent 'Wine' and 'FineWine'";
}
std::string Symbol_Child::getAbility() {
    return "Child: Adjacent 'Dog' gain 2x money, gains 2$ for every adjacent 'Dog'";
}
std::string Symbol_Vet::getAbility() {
    return "Vet: Adjacent 'Dog' gain 5x money, gains 3$ for every adjacent 'Dog'";
}
std::string Symbol_Owner::getAbility() {
    return "Owner: Adjacent 'Dog' gain 2x money, gains 3$ for every adjacent 'Child'";
}
std::string Symbol_Stranger::getAbility() {
    return "Stranger: 80% chance (adjacent 'Dog' gain 4x money, gains 2$ for every adjacent 'Dog'), 20% chance (adjacent 'Dog' make 0 money)";
}
std::string Symbol_Insect::getAbility() {
    return "Insect: 10% chance (destroys adjacent 'Flower'), 90% chance (adjacent 'Flower' make 0 money), gains 5$ for every adjacent 'Insect'";
}
std::string Symbol_Granny::getAbility() {
    return "Granny: Legacy grows 10$ ,adjacent 'Child' and 'Owner' gain 2x money, legacy grows 5$ for every adjacent 'Child' and 'Owner', has a 20% chance to destroy itself and gain the entire value of the legacy, has a 50% chance to turn 'Owner' on the board into 'Drunk' when destroyed";
}
std::string Symbol_TreasureChest::getAbility() {
    return "TreasureChest: Adjacent 'Key' can open it, gains 29 when opened, destroys itself after being opened";
}
std::string Symbol_TreasureKey::getAbility() {
    return "TreasureKey: Can open adjacent 'TreasureChest', destroys itself after being used";
}
std::string Symbol_Coin::getAbility() {
    return "Coin";
}