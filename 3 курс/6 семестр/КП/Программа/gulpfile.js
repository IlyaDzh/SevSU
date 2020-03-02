const gulp = require('gulp');
const sass = require('gulp-sass');

gulp.task('scss', function (done) {
    gulp.src('./docs/scss/style.scss')
        .pipe(sass({ outputStyle: 'compressed' }).on('error', sass.logError))
        .pipe(gulp.dest('./docs/css/'));
    done();
});

gulp.task('watch', function () {
    gulp.watch('./docs/scss/*.scss', gulp.parallel('scss'));
});