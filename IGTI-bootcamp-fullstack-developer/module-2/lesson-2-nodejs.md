# nodejs lesson 2

## Introduction to nodejs
Node.js is an open-source, cross-platform, javascript runtime environment that executes JavaScript code outside a web browser. Node.js lets developers use JavaScript to write command line tools and for server-side scripting--- running scripts server-side to produce dynamic web page content before the page is sent to the users web browser, Consequently, Node.js represents a 'javascript everywhere' paradigm, unifying web-application development around a single programming languagem rather than different languages for server and client side scripts.

## concepts

Though .js is the standard filename extension for JavaScript code, the name "node.js" does not refer to  a particular file in this context and is merely the name of the product. Node.js has an event-driven architecture capable of asynchronous I/O. These design choices aim to optimize throughout and scalability in web applications with many input/output operations, as well as for real-time web applications.

## fundamentals

**Threading**
Node.js operates on a single-thread event loop, using non-blocking I/O calls, allowing it to support tens of thousands of concurrent connections without incurring the cost of thread context switching. The design of sharing a single thread among all the requests that use the observer pattern is intended for building highly concurrent applications, where any function performing I/O must use a callback. To accommodate the single-threaded event loop, Node.js uses the libuv library---which, in turn, uses a fixed-sized thread pool that handles some of the non-blocking asynchronous I/O operations.

**V8**
V8 is the javascript execution engine which was initially built for google chrome. It was then open-sourced by google in 2008. Written in C++, V8 compiles Javascript source code to native machine code at runtime. as of 2016, it also includes Ignition, a bytecode interpreter.

**Package management**
npm is the pre-installed package manager for the node.js server platform. it installs Node.js programs from the npm registry, organizing the installation and management of third party node.js programs. Packages in the npm registry can range from simple helper libraries such as Lodash to task runners as Grunt.

**Unified API**
Node.js can be combined with a browser, a database that supports JSON data (such as Postgres, MongoDB, CouchDB) and JSON for a unified javascript development stack. with the adaptation of what were essentially server side development patterns such as MVC, MVP, MVVM etc,. Node.js allows the reuse of the same model and service interface between client side and server side.





## conclusion

fonts: https://en.wikipedia.org/wiki/Node.js