'use strict';

var gulp = require('gulp'),
    sass = require('gulp-sass'),
    autoprefixer = require('gulp-autoprefixer'),
    sassGlob = require('gulp-sass-glob'),
    sassLint = require('gulp-sass-lint'),
    livereload = require('gulp-livereload'),
    del = require('del'),
    notify = require("gulp-notify"),
    sourcemaps = require('gulp-sourcemaps');

gulp.task('clean', function() {
  return del([
    '../css'
  ], {
    force: true
  });
});

gulp.task('sass', function() {
  gulp.src('../sass/**/*.scss')
    .pipe(sourcemaps.init())
    .pipe(sassGlob())
    .pipe(sass().on('error', notify.onError('<%= error.message %>')))
    .pipe(autoprefixer())
    .pipe(sourcemaps.write())
    .pipe(gulp.dest('../css'))
    .pipe(livereload());
});

gulp.task('watch', function() {
    livereload.listen();
    gulp.watch('../sass/**/*.scss', ['sass']);
});

gulp.task('default', ['clean', 'sass', 'watch']);
