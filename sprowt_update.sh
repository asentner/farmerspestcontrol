#! /usr/bin/env sh
drush up --no-core &&
drush make --no-core ./profiles/sprowt/patches.make.yaml --contrib-destination=profiles/sprowt -y