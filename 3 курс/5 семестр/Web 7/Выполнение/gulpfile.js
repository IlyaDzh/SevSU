var gulp = require('gulp');
var sass = require('gulp-sass');
var coffee = require('gulp-coffee');

gulp.task('scss', function (done) {
    gulp.src('app/scss/*.scss')
        .pipe(sass({ outputStyle: 'expanded' }).on('error', sass.logError))
        .pipe(gulp.dest('app/css/'));
    done();
});

gulp.task('coffee', function (done) {
    gulp.src('app/coffee/*.coffee')
        .pipe(coffee({ bare: true }))
        .pipe(gulp.dest('app/js/'));
    done();
});

gulp.task('watch', function () {
    gulp.watch('app/scss/*.scss', gulp.parallel('scss'));
    gulp.watch('app/coffee/*.coffee', gulp.parallel('coffee'));
});