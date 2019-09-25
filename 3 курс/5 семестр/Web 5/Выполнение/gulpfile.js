var gulp = require('gulp');
var haml = require('gulp-haml');

gulp.task('convertHaml', function (done) {
    gulp.src('./haml/*.haml')
        .pipe(haml())
        .pipe(gulp.dest('./'));
    done();
});

gulp.task('watch', function () {
    gulp.watch('./haml/*.haml', gulp.parallel('convertHaml'));
});