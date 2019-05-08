'use strict';

var gulp = require('gulp'),
    sass = require('gulp-sass'),
    autoprefixer = require('gulp-autoprefixer'),
    sassGlob = require('gulp-sass-glob'),
    sassLint = require('gulp-sass-lint'),
    livereload = require('gulp-livereload'),
    del = require('del');
var notify = require("gulp-notify");
var sourcemaps = require('gulp-sourcemaps');
var concat = require('gulp-concat');

gulp.task('clean', function() {
  return del([
    '../css'
  ], {
    force: true
  });
});

gulp.task('clean-js', function() {
  return del([
    '../dist/js'
  ], {
    force: true
  });
});

gulp.task('clean-parsetables', function() {
  return del([
    '../dist/css'
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
      .pipe(gulp.dest('../css'))
      .pipe(livereload());
  gulp.src('../sass-colors/**/*.scss')
      .pipe(sourcemaps.init())
      .pipe(sassGlob())
      .pipe(sass().on('error', notify.onError('<%= error.message %>')))
      .pipe(autoprefixer())
      .pipe(gulp.dest('../css'))
      .pipe(livereload());
});

gulp.task('sass-parsetables', function() {
  gulp.src('../src/sass/**/*.scss')
      .pipe(sourcemaps.init())
      .pipe(sassGlob())
      .pipe(sass().on('error', notify.onError('<%= error.message %>')))
      .pipe(autoprefixer())
      .pipe(gulp.dest('../dist/css'))
      .pipe(livereload());
});

gulp.task('js',function(){
  gulp.src(['./node_modules/papaparse/papaparse.min.js','../src/js/index.js'])
      .pipe(concat('app.js'))
      .pipe(gulp.dest('../dist/js'));
});

gulp.task('watch', function() {
  livereload.listen();
  gulp.watch('../sass/**/*.scss', ['sass']);
  gulp.watch('../sass-colors/**/*.scss', ['sass']);
});

gulp.task('watch-js',function(){
  gulp.watch('../src/js/index.js',['js']);
});

gulp.task('default', ['clean', 'sass', 'watch']);

gulp.task('default-parsetables', ['clean', 'sass', 'watch']);

gulp.task('default-js',['clean-js','js','watch-js']);
