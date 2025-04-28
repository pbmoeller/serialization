# Serialization

## Test Coverage

``` sh
cd ./out/build/linux-debug
mkdir lcoverage
lcov --capture --directory ../ --output-file lcoverage/main_coverage.info
lcov --capture --directory ../ --output-file lcoverage/main_coverage.info --ignore-errors mismatch

genhtml lcoverage/main_coverage.info --output-directory lcoverage
```