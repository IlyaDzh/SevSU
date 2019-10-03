var gulp = require('gulp');
var haml = require('gulp-haml');

gulp.task('convertHaml', function (done) {
    gulp.src('./app/haml/*.haml')
        .pipe(haml({
            ext: '.php'
        }))
        .pipe(gulp.dest('./app'));
    done();
});

gulp.task('watch', function () {
    gulp.watch('./app/haml/*.haml', gulp.parallel('convertHaml'));
});