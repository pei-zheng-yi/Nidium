---
description: What is nidium
---

## What is nidium?

_tl;dr;_  
_nidium helps you build mobile applications using JavaScript. You write your application once, it then works on Android and iOS._


nidium is a complete ecosystem for building modern mobile applications using web technologies.  
In practice, this means that you write your mobile application using **modern JavaScript** and **markup language**.

Unlike other commonly used framework, nidium is not based on a webview or any existing rendering engine.  
Behind the scene, it implements **its own rendering engine** (somewhat comparable to what a Web browser does).

Related topic : [Reinventing the weel]

## What problems is nidium trying to solve?

nidium aims to expose an easily hackable environment for app developers.

With nidium, you can experiment without being dependent to blink or webkit, like Electron is for example. Moreover, nidium’s footprint is small (about 20 MB statically linked with all dependencies and it typically consumes just a few megabytes of virtual memory).

We strive to target a large spectrum of devices, and our short term goal is to ship on **major mobile operating systems**.

[Reinventing the weel]: {{ Guide.URL('misc', 'reinventing-the-wheel') }}

## Developer experience and ease of use

nidium was designed with **developer experience** (DX) in mind.  
Unlike existing solutions, nidium doesn't require extensive use of the command line or third-party transpiler like Babel or Webpack.

### Debugging

nidium supports **Chrome DevTools** out of the box.

### Emulator

It comes with its own mobile emulator which usually boot in less than **1 second**.


## Hello World

```js
var x = 42;
```
