'use strict';

var gulp = require('gulp'),
    sass = require('gulp-sass'),
    autoprefixer = require('gulp-autoprefixer'),
    sassGlob = require('gulp-sass-glob'),
    livereload = require('gulp-livereload'),
    del = require('del');

gulp.task('sass', function() {
  gulp.src('../sass/**/*.scss')
    .pipe(sassGlob())
    .pipe(sass().on('error', sass.logError))
    .pipe(autoprefixer())
    .pipe(gulp.dest('../css'))
});

gulp.task('watch', function() {
    gulp.watch('../sass/**/*.scss', ['sass']);
});

gulp.task('default', ['sass', 'watch']);
