var gulp = require('gulp');
var sass = require('gulp-sass');

gulp.task('scss', function (done) {
    gulp.src('app/scss/*.scss')
        .pipe(sass({outputStyle: 'expanded'}).on('error', sass.logError))
        .pipe(gulp.dest('app/css/'));
    done();
});

gulp.task('watch', function () {
    gulp.watch('app/scss/*.scss', gulp.parallel('scss'));
});