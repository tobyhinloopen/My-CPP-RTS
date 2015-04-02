#import "unit_health_manager.h"

using namespace std;

UnitHealthManager::UnitHealthManager(const shared_ptr<const vector<shared_ptr<Component>>> components):
Componentable(components),
_initial_health(health_for_components(components)) {
}

int UnitHealthManager::initial_health() const {
  return _initial_health;
}

int UnitHealthManager::health() const {
  return health_for_components(components);
}

bool UnitHealthManager::alive() const {
  return health() > 0;
}

bool UnitHealthManager::dead() const {
  return health() == 0;
}

int UnitHealthManager::health_for_components(const shared_ptr<const vector<shared_ptr<Component>>> components) {
  int health = 0;
  for(const auto component : *components)
    health += component->health();
  return health;
}
