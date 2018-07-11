; Specify the version of Drupal being used.
core = 7.x

; Specify the api version of Drush Make.
api = 2

projects[link][patch][] = 'https://www.drupal.org/files/issues/2018-03-20/link_anchors_and_queries-2654246-22.patch'
projects[paragraphs][patch][] = 'https://www.drupal.org/files/issues/clonefatalerror-2897975-1.patch'
projects[smtp][patch][] = 'https://www.drupal.org/files/issues/2018-06-04/2753115-41-smtp-multiple-to-addresses-error.patch'
projects[taxonomy_dupecheck][patch][] = 'https://www.drupal.org/files/issues/notice%EF%80%BA-undefined-index%EF%80%BA-term.patch'