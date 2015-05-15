#import "component_template_factory.h"

engine_template component_template_factory::create_engine_template() {
  engine_template sample_engine;
  sample_engine.complexity = 100;
  sample_engine.mass = 100;
  sample_engine.health = 40;
  sample_engine.volatility = 40;
  return sample_engine;
}

weapon_template component_template_factory::create_laser_weapon_template() {
  weapon_template sample_laser;
  sample_laser.complexity = 40;
  sample_laser.mass = 20;
  sample_laser.health = 10;
  sample_laser.volatility = 20;
  return sample_laser;
}

weapon_template component_template_factory::create_cannon_weapon_template() {
  weapon_template sample_cannon;
  sample_cannon.complexity = 60;
  sample_cannon.mass = 40;
  sample_cannon.health = 20;
  sample_cannon.volatility = 5;
  return sample_cannon;
}

reactor_template component_template_factory::create_reactor_template() {
  reactor_template sample_reactor;
  sample_reactor.complexity = 40;
  sample_reactor.mass = 40;
  sample_reactor.health = 60;
  sample_reactor.volatility = 40;
  return sample_reactor;
}
