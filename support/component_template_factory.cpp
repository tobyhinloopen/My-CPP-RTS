#import "component_template_factory.h"

EngineTemplate ComponentTemplateFactory::create_engine_template() {
  EngineTemplate sample_engine;
  sample_engine.complexity = 100;
  sample_engine.mass = 100;
  sample_engine.health = 40;
  sample_engine.volatility = 40;
  return sample_engine;
}

WeaponTemplate ComponentTemplateFactory::create_laser_weapon_template() {
  WeaponTemplate sample_laser;
  sample_laser.complexity = 40;
  sample_laser.mass = 20;
  sample_laser.health = 10;
  sample_laser.volatility = 20;
  return sample_laser;
}

WeaponTemplate ComponentTemplateFactory::create_cannon_weapon_template() {
  WeaponTemplate sample_cannon;
  sample_cannon.complexity = 60;
  sample_cannon.mass = 40;
  sample_cannon.health = 20;
  sample_cannon.volatility = 5;
  return sample_cannon;
}

ReactorTemplate ComponentTemplateFactory::create_reactor_template() {
  ReactorTemplate sample_reactor;
  sample_reactor.complexity = 40;
  sample_reactor.mass = 40;
  sample_reactor.health = 60;
  sample_reactor.volatility = 40;
  return sample_reactor;
}
