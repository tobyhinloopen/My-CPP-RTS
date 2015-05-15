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

double unit_template::mass() const {
  double mass = 0.0;
  for(const auto component_template : _component_templates)
    mass += component_template.mass;
  return mass;
}

double unit_template::complexity() const {
  double complexity = 0.0;
  for(const auto component_template : _component_templates)
    complexity += component_template.complexity;
  return complexity;
}

double unit_template::health() const {
  double health = 0.0;
  for(const auto component_template : _component_templates)
    health += component_template.health;
  return health;
}
