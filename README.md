# InfluxDB Line Writer Protocol

## Introduction

This library helps generating files according to InfluxDB Line Writer Protocol.   

The protocol contains some escaping and encoding rules so it is easy to create files containing errors.

By using this fully tested library it becomes easy to create files that adhere to the 
InfluxDB Line Writer Protocol correctly.  

See:
* [Line Protocol 1.8 Reference](https://docs.influxdata.com/influxdb/v1.8/write_protocols/line_protocol_reference/)
* [Line Protocol 2.0 Reference](https://v2.docs.influxdata.com/v2.0/reference/syntax/line-protocol/)

## License

MIT
Copyright 2020 CrossCode / P. Vollebregt 

See the file [LICENSE](LICENSE).

## Design choices

* An easy to use interface for using C++ output operators for consumers of this library.
* Modern C++ principles are used. 
* SOLID principles are used in order to create a maintainable and fully tested library.
* TDD is used to create new features.
* DRY principles are followed strongly.
* Expect and handle exceptions. Exceptions raised from this code are documented, but exceptions from calls into STL are
  not explicitly documented. This library defines only one exception influxdb::validation_exception. It's thrown when
  invalid input is given at any point. This library tries to validate input as early as possible. 

## Examples

Examples will follow later.

See units tests under [tests/](tests)

## TODO

* Allow setting timestamp resolution.