Drupal Recruit offers basic job and applicant tracking. Jobs are implemented using a standard content type and applications are implemented using an entity type.

Currently the application entity type comes with two fields: first and last name. However, you can add your own fields from the "Application types" page (admin/structure/application-types).

## Requirements

- [Entity API](https://drupal.org/project/entity)
- [Entity reference](https://drupal.org/project/entityreference)
- [Ctools](https://drupal.org/project/ctools)
- [Views](https://drupal.org/project/views)

## Installation

Install both recruit and recruit_application.

## Managing Jobs

- Create a job by going to Content, "Add content" and click on Job
- Select an application type from the application field and you're good to go.

## Managing Applications

> Make sure you enable the recruit_application module.

- To manage application types or to create your own, go to Structure and "Application types".
- You can view all applications by going to Content, Applications.


## Maintainer