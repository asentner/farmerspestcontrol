'use strict';

var gulp = require('gulp');
var sass = require('gulp-sass');
var sourcemaps = require('gulp-sourcemaps');
var autoprefixer = require('gulp-autoprefixer');
var sassGlob = require('gulp-sass-glob');
var livereload = require('gulp-livereload');
var notify = require("gulp-notify");

gulp.task('sass:prod', function () {
  gulp.src('../sass/interstatepest.styles.scss')
    .pipe(sassGlob())
    .pipe(sass().on('error', notify.onError('<%= error.message %>')))
    .pipe(autoprefixer({
       browsers: ['last 2 version']
    }))
    .pipe(gulp.dest('../css'));
});

gulp.task('sass:dev', function () {
  gulp.src('../sass/interstatepest.styles.scss')
    .pipe(sourcemaps.init())
    .pipe(sassGlob())
    .pipe(sass().on('error', notify.onError('<%= error.message %>')))
    .pipe(autoprefixer({
      browsers: ['last 2 version']
    }))
    .pipe(sourcemaps.write('.'))
    .pipe(gulp.dest('../css'))
    .pipe(livereload());
});

gulp.task('sass:watch', function () {
  livereload.listen();
  gulp.watch('../sass/**/*', ['sass:dev']);
});

gulp.task('default', ['sass:dev', 'sass:watch']);
