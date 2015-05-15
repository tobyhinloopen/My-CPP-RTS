#import "unit_template.h"
#import "template_component.h"

unit_template::unit_template() {}

void unit_template::add(const component_template & component_template) {
  _component_templates.push_back(component_template);
}

std::unique_ptr<component_set> unit_template::create_components() const {
  auto components = std::unique_ptr<component_set>(new component_set());
  for(const auto component_template : _component_templates)
    components->push_back(std::make_shared<template_component>(component_template));
  return components;
}

mass_t unit_template::mass() const {
  mass_t mass = 0;
  for(const auto component_template : _component_templates)
    mass += component_template.mass;
  return mass;
}

complexity_t unit_template::complexity() const {
  complexity_t complexity = 0;
  for(const auto component_template : _component_templates)
    complexity += component_template.complexity;
  return complexity;
}

health_t unit_template::health() const {
  health_t health = 0;
  for(const auto component_template : _component_templates)
    health += component_template.health;
  return health;
}
