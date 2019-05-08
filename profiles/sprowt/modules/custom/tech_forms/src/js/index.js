/* @license
Papa Parse
v4.6.1
https://github.com/mholt/PapaParse
License: MIT
*/
Array.isArray||(Array.isArray=function(e){return"[object Array]"===Object.prototype.toString.call(e)}),function(e,t){"function"==typeof define&&define.amd?define([],t):"object"==typeof module&&"undefined"!=typeof exports?module.exports=t():e.Papa=t()}(this,function(){"use strict";var s,e,f="undefined"!=typeof self?self:"undefined"!=typeof window?window:void 0!==f?f:{},n=!f.document&&!!f.postMessage,o=n&&/(\?|&)papaworker(=|&|$)/.test(f.location.search),a=!1,h={},u=0,v={parse:function(e,t){var i=(t=t||{}).dynamicTyping||!1;M(i)&&(t.dynamicTypingFunction=i,i={});if(t.dynamicTyping=i,t.transform=!!M(t.transform)&&t.transform,t.worker&&v.WORKERS_SUPPORTED){var r=function(){if(!v.WORKERS_SUPPORTED)return!1;if(!a&&null===v.SCRIPT_PATH)throw new Error("Script path cannot be determined automatically when Papa Parse is loaded asynchronously. You need to set Papa.SCRIPT_PATH manually.");var e=v.SCRIPT_PATH||s;e+=(-1!==e.indexOf("?")?"&":"?")+"papaworker";var t=new f.Worker(e);return t.onmessage=y,t.id=u++,h[t.id]=t}();return r.userStep=t.step,r.userChunk=t.chunk,r.userComplete=t.complete,r.userError=t.error,t.step=M(t.step),t.chunk=M(t.chunk),t.complete=M(t.complete),t.error=M(t.error),delete t.worker,void r.postMessage({input:e,config:t,workerId:r.id})}var n=null;{if(e===v.NODE_STREAM_INPUT)return(n=new g(t)).getStream();"string"==typeof e?n=t.download?new c(t):new _(t):!0===e.readable&&M(e.read)&&M(e.on)?n=new m(t):(f.File&&e instanceof File||e instanceof Object)&&(n=new p(t))}return n.stream(e)},unparse:function(e,t){var r=!1,l=!0,c=",",p="\r\n",n='"',i=!1;!function(){if("object"!=typeof t)return;"string"!=typeof t.delimiter||v.BAD_DELIMITERS.filter(function(e){return-1!==t.delimiter.indexOf(e)}).length||(c=t.delimiter);("boolean"==typeof t.quotes||Array.isArray(t.quotes))&&(r=t.quotes);"boolean"!=typeof t.skipEmptyLines&&"string"!=typeof t.skipEmptyLines||(i=t.skipEmptyLines);"string"==typeof t.newline&&(p=t.newline);"string"==typeof t.quoteChar&&(n=t.quoteChar);"boolean"==typeof t.header&&(l=t.header)}();var s=new RegExp(n,"g");"string"==typeof e&&(e=JSON.parse(e));if(Array.isArray(e)){if(!e.length||Array.isArray(e[0]))return o(null,e,i);if("object"==typeof e[0])return o(a(e[0]),e,i)}else if("object"==typeof e)return"string"==typeof e.data&&(e.data=JSON.parse(e.data)),Array.isArray(e.data)&&(e.fields||(e.fields=e.meta&&e.meta.fields),e.fields||(e.fields=Array.isArray(e.data[0])?e.fields:a(e.data[0])),Array.isArray(e.data[0])||"object"==typeof e.data[0]||(e.data=[e.data])),o(e.fields||[],e.data||[],i);throw"exception: Unable to serialize unrecognized input";function a(e){if("object"!=typeof e)return[];var t=[];for(var i in e)t.push(i);return t}function o(e,t,i){var r="";"string"==typeof e&&(e=JSON.parse(e)),"string"==typeof t&&(t=JSON.parse(t));var n=Array.isArray(e)&&0<e.length,s=!Array.isArray(t[0]);if(n&&l){for(var a=0;a<e.length;a++)0<a&&(r+=c),r+=_(e[a],a);0<t.length&&(r+=p)}for(var o=0;o<t.length;o++){var h=n?e.length:t[o].length,u=n?e:t[o];if("greedy"!==i||""!==u.join("").trim()){for(var f=0;f<h;f++){0<f&&(r+=c);var d=n&&s?e[f]:f;r+=_(t[o][d],f)}o<t.length-1&&(!i||0<h)&&(r+=p)}}return r}function _(e,t){if(null==e)return"";if(e.constructor===Date)return JSON.stringify(e).slice(1,25);e=e.toString().replace(s,n+n);var i="boolean"==typeof r&&r||Array.isArray(r)&&r[t]||function(e,t){for(var i=0;i<t.length;i++)if(-1<e.indexOf(t[i]))return!0;return!1}(e,v.BAD_DELIMITERS)||-1<e.indexOf(c)||" "===e.charAt(0)||" "===e.charAt(e.length-1);return i?n+e+n:e}}};if(v.RECORD_SEP=String.fromCharCode(30),v.UNIT_SEP=String.fromCharCode(31),v.BYTE_ORDER_MARK="\ufeff",v.BAD_DELIMITERS=["\r","\n",'"',v.BYTE_ORDER_MARK],v.WORKERS_SUPPORTED=!n&&!!f.Worker,v.SCRIPT_PATH=null,v.NODE_STREAM_INPUT=1,v.LocalChunkSize=10485760,v.RemoteChunkSize=5242880,v.DefaultDelimiter=",",v.Parser=C,v.ParserHandle=i,v.NetworkStreamer=c,v.FileStreamer=p,v.StringStreamer=_,v.ReadableStreamStreamer=m,v.DuplexStreamStreamer=g,f.jQuery){var d=f.jQuery;d.fn.parse=function(o){var i=o.config||{},h=[];return this.each(function(e){if(!("INPUT"===d(this).prop("tagName").toUpperCase()&&"file"===d(this).attr("type").toLowerCase()&&f.FileReader)||!this.files||0===this.files.length)return!0;for(var t=0;t<this.files.length;t++)h.push({file:this.files[t],inputElem:this,instanceConfig:d.extend({},i)})}),e(),this;function e(){if(0!==h.length){var e,t,i,r,n=h[0];if(M(o.before)){var s=o.before(n.file,n.inputElem);if("object"==typeof s){if("abort"===s.action)return e="AbortError",t=n.file,i=n.inputElem,r=s.reason,void(M(o.error)&&o.error({name:e},t,i,r));if("skip"===s.action)return void u();"object"==typeof s.config&&(n.instanceConfig=d.extend(n.instanceConfig,s.config))}else if("skip"===s)return void u()}var a=n.instanceConfig.complete;n.instanceConfig.complete=function(e){M(a)&&a(e,n.file,n.inputElem),u()},v.parse(n.file,n.instanceConfig)}else M(o.complete)&&o.complete()}function u(){h.splice(0,1),e()}}}function l(e){this._handle=null,this._finished=!1,this._completed=!1,this._input=null,this._baseIndex=0,this._partialLine="",this._rowCount=0,this._start=0,this._nextChunk=null,this.isFirstChunk=!0,this._completeResults={data:[],errors:[],meta:{}},function(e){var t=E(e);t.chunkSize=parseInt(t.chunkSize),e.step||e.chunk||(t.chunkSize=null);this._handle=new i(t),(this._handle.streamer=this)._config=t}.call(this,e),this.parseChunk=function(e,t){if(this.isFirstChunk&&M(this._config.beforeFirstChunk)){var i=this._config.beforeFirstChunk(e);void 0!==i&&(e=i)}this.isFirstChunk=!1;var r=this._partialLine+e;this._partialLine="";var n=this._handle.parse(r,this._baseIndex,!this._finished);if(!this._handle.paused()&&!this._handle.aborted()){var s=n.meta.cursor;this._finished||(this._partialLine=r.substring(s-this._baseIndex),this._baseIndex=s),n&&n.data&&(this._rowCount+=n.data.length);var a=this._finished||this._config.preview&&this._rowCount>=this._config.preview;if(o)f.postMessage({results:n,workerId:v.WORKER_ID,finished:a});else if(M(this._config.chunk)&&!t){if(this._config.chunk(n,this._handle),this._handle.paused()||this._handle.aborted())return;n=void 0,this._completeResults=void 0}return this._config.step||this._config.chunk||(this._completeResults.data=this._completeResults.data.concat(n.data),this._completeResults.errors=this._completeResults.errors.concat(n.errors),this._completeResults.meta=n.meta),this._completed||!a||!M(this._config.complete)||n&&n.meta.aborted||(this._config.complete(this._completeResults,this._input),this._completed=!0),a||n&&n.meta.paused||this._nextChunk(),n}},this._sendError=function(e){M(this._config.error)?this._config.error(e):o&&this._config.error&&f.postMessage({workerId:v.WORKER_ID,error:e,finished:!1})}}function c(e){var r;(e=e||{}).chunkSize||(e.chunkSize=v.RemoteChunkSize),l.call(this,e),this._nextChunk=n?function(){this._readChunk(),this._chunkLoaded()}:function(){this._readChunk()},this.stream=function(e){this._input=e,this._nextChunk()},this._readChunk=function(){if(this._finished)this._chunkLoaded();else{if(r=new XMLHttpRequest,this._config.withCredentials&&(r.withCredentials=this._config.withCredentials),n||(r.onload=R(this._chunkLoaded,this),r.onerror=R(this._chunkError,this)),r.open("GET",this._input,!n),this._config.downloadRequestHeaders){var e=this._config.downloadRequestHeaders;for(var t in e)r.setRequestHeader(t,e[t])}if(this._config.chunkSize){var i=this._start+this._config.chunkSize-1;r.setRequestHeader("Range","bytes="+this._start+"-"+i),r.setRequestHeader("If-None-Match","webkit-no-cache")}try{r.send()}catch(e){this._chunkError(e.message)}n&&0===r.status?this._chunkError():this._start+=this._config.chunkSize}},this._chunkLoaded=function(){4===r.readyState&&(r.status<200||400<=r.status?this._chunkError():(this._finished=!this._config.chunkSize||this._start>function(e){var t=e.getResponseHeader("Content-Range");if(null===t)return-1;return parseInt(t.substr(t.lastIndexOf("/")+1))}(r),this.parseChunk(r.responseText)))},this._chunkError=function(e){var t=r.statusText||e;this._sendError(new Error(t))}}function p(e){var r,n;(e=e||{}).chunkSize||(e.chunkSize=v.LocalChunkSize),l.call(this,e);var s="undefined"!=typeof FileReader;this.stream=function(e){this._input=e,n=e.slice||e.webkitSlice||e.mozSlice,s?((r=new FileReader).onload=R(this._chunkLoaded,this),r.onerror=R(this._chunkError,this)):r=new FileReaderSync,this._nextChunk()},this._nextChunk=function(){this._finished||this._config.preview&&!(this._rowCount<this._config.preview)||this._readChunk()},this._readChunk=function(){var e=this._input;if(this._config.chunkSize){var t=Math.min(this._start+this._config.chunkSize,this._input.size);e=n.call(e,this._start,t)}var i=r.readAsText(e,this._config.encoding);s||this._chunkLoaded({target:{result:i}})},this._chunkLoaded=function(e){this._start+=this._config.chunkSize,this._finished=!this._config.chunkSize||this._start>=this._input.size,this.parseChunk(e.target.result)},this._chunkError=function(){this._sendError(r.error)}}function _(e){var i;l.call(this,e=e||{}),this.stream=function(e){return i=e,this._nextChunk()},this._nextChunk=function(){if(!this._finished){var e=this._config.chunkSize,t=e?i.substr(0,e):i;return i=e?i.substr(e):"",this._finished=!i,this.parseChunk(t)}}}function m(e){l.call(this,e=e||{});var t=[],i=!0,r=!1;this.pause=function(){l.prototype.pause.apply(this,arguments),this._input.pause()},this.resume=function(){l.prototype.resume.apply(this,arguments),this._input.resume()},this.stream=function(e){this._input=e,this._input.on("data",this._streamData),this._input.on("end",this._streamEnd),this._input.on("error",this._streamError)},this._checkIsFinished=function(){r&&1===t.length&&(this._finished=!0)},this._nextChunk=function(){this._checkIsFinished(),t.length?this.parseChunk(t.shift()):i=!0},this._streamData=R(function(e){try{t.push("string"==typeof e?e:e.toString(this._config.encoding)),i&&(i=!1,this._checkIsFinished(),this.parseChunk(t.shift()))}catch(e){this._streamError(e)}},this),this._streamError=R(function(e){this._streamCleanUp(),this._sendError(e)},this),this._streamEnd=R(function(){this._streamCleanUp(),r=!0,this._streamData("")},this),this._streamCleanUp=R(function(){this._input.removeListener("data",this._streamData),this._input.removeListener("end",this._streamEnd),this._input.removeListener("error",this._streamError)},this)}function g(e){var t=require("stream").Duplex,i=E(e),r=!0,n=!1,s=[],a=null;this._onCsvData=function(e){for(var t=e.data,i=0;i<t.length;i++)a.push(t[i])||this._handle.paused()||this._handle.pause()},this._onCsvComplete=function(){a.push(null)},i.step=R(this._onCsvData,this),i.complete=R(this._onCsvComplete,this),l.call(this,i),this._nextChunk=function(){n&&1===s.length&&(this._finished=!0),s.length?s.shift()():r=!0},this._addToParseQueue=function(e,t){s.push(R(function(){if(this.parseChunk("string"==typeof e?e:e.toString(i.encoding)),M(t))return t()},this)),r&&(r=!1,this._nextChunk())},this._onRead=function(){this._handle.paused()&&this._handle.resume()},this._onWrite=function(e,t,i){this._addToParseQueue(e,i)},this._onWriteComplete=function(){n=!0,this._addToParseQueue("")},this.getStream=function(){return a},(a=new t({readableObjectMode:!0,decodeStrings:!1,read:R(this._onRead,this),write:R(this._onWrite,this)})).once("finish",R(this._onWriteComplete,this))}function i(m){var a,o,h,r=/^\s*-?(\d*\.?\d+|\d+\.?\d*)(e[-+]?\d+)?\s*$/i,n=/(\d{4}-[01]\d-[0-3]\dT[0-2]\d:[0-5]\d:[0-5]\d\.\d+([+-][0-2]\d:[0-5]\d|Z))|(\d{4}-[01]\d-[0-3]\dT[0-2]\d:[0-5]\d:[0-5]\d([+-][0-2]\d:[0-5]\d|Z))|(\d{4}-[01]\d-[0-3]\dT[0-2]\d:[0-5]\d([+-][0-2]\d:[0-5]\d|Z))/,t=this,i=0,s=0,u=!1,e=!1,f=[],d={data:[],errors:[],meta:{}};if(M(m.step)){var l=m.step;m.step=function(e){if(d=e,p())c();else{if(c(),0===d.data.length)return;i+=e.data.length,m.preview&&i>m.preview?o.abort():l(d,t)}}}function g(e){return"greedy"===m.skipEmptyLines?""===e.join("").trim():1===e.length&&0===e[0].length}function c(){if(d&&h&&(y("Delimiter","UndetectableDelimiter","Unable to auto-detect delimiting character; defaulted to '"+v.DefaultDelimiter+"'"),h=!1),m.skipEmptyLines)for(var e=0;e<d.data.length;e++)g(d.data[e])&&d.data.splice(e--,1);return p()&&function(){if(!d)return;for(var e=0;p()&&e<d.data.length;e++)for(var t=0;t<d.data[e].length;t++){var i=d.data[e][t];m.trimHeaders&&(i=i.trim()),f.push(i)}d.data.splice(0,1)}(),function(){if(!d||!m.header&&!m.dynamicTyping&&!m.transform)return d;for(var e=0;e<d.data.length;e++){var t,i=m.header?{}:[];for(t=0;t<d.data[e].length;t++){var r=t,n=d.data[e][t];m.header&&(r=t>=f.length?"__parsed_extra":f[t]),m.transform&&(n=m.transform(n,r)),n=_(r,n),"__parsed_extra"===r?(i[r]=i[r]||[],i[r].push(n)):i[r]=n}d.data[e]=i,m.header&&(t>f.length?y("FieldMismatch","TooManyFields","Too many fields: expected "+f.length+" fields but parsed "+t,s+e):t<f.length&&y("FieldMismatch","TooFewFields","Too few fields: expected "+f.length+" fields but parsed "+t,s+e))}m.header&&d.meta&&(d.meta.fields=f);return s+=d.data.length,d}()}function p(){return m.header&&0===f.length}function _(e,t){return i=e,m.dynamicTypingFunction&&void 0===m.dynamicTyping[i]&&(m.dynamicTyping[i]=m.dynamicTypingFunction(i)),!0===(m.dynamicTyping[i]||m.dynamicTyping)?"true"===t||"TRUE"===t||"false"!==t&&"FALSE"!==t&&(r.test(t)?parseFloat(t):n.test(t)?new Date(t):""===t?null:t):t;var i}function y(e,t,i,r){d.errors.push({type:e,code:t,message:i,row:r})}this.parse=function(e,t,i){var r=m.quoteChar||'"';if(m.newline||(m.newline=function(e,t){e=e.substr(0,1048576);var i=new RegExp(k(t)+"([^]*?)"+k(t),"gm"),r=(e=e.replace(i,"")).split("\r"),n=e.split("\n"),s=1<n.length&&n[0].length<r[0].length;if(1===r.length||s)return"\n";for(var a=0,o=0;o<r.length;o++)"\n"===r[o][0]&&a++;return a>=r.length/2?"\r\n":"\r"}(e,r)),h=!1,m.delimiter)M(m.delimiter)&&(m.delimiter=m.delimiter(e),d.meta.delimiter=m.delimiter);else{var n=function(e,t,i,r){for(var n,s,a,o=[",","\t","|",";",v.RECORD_SEP,v.UNIT_SEP],h=0;h<o.length;h++){var u=o[h],f=0,d=0,l=0;a=void 0;for(var c=new C({comments:r,delimiter:u,newline:t,preview:10}).parse(e),p=0;p<c.data.length;p++)if(i&&g(c.data[p]))l++;else{var _=c.data[p].length;d+=_,void 0!==a?1<_&&(f+=Math.abs(_-a),a=_):a=_}0<c.data.length&&(d/=c.data.length-l),(void 0===s||f<s)&&1.99<d&&(s=f,n=u)}return{successful:!!(m.delimiter=n),bestDelimiter:n}}(e,m.newline,m.skipEmptyLines,m.comments);n.successful?m.delimiter=n.bestDelimiter:(h=!0,m.delimiter=v.DefaultDelimiter),d.meta.delimiter=m.delimiter}var s=E(m);return m.preview&&m.header&&s.preview++,a=e,o=new C(s),d=o.parse(a,t,i),c(),u?{meta:{paused:!0}}:d||{meta:{paused:!1}}},this.paused=function(){return u},this.pause=function(){u=!0,o.abort(),a=a.substr(o.getCharIndex())},this.resume=function(){u=!1,t.streamer.parseChunk(a,!0)},this.aborted=function(){return e},this.abort=function(){e=!0,o.abort(),d.meta.aborted=!0,M(m.complete)&&m.complete(d),a=""}}function k(e){return e.replace(/[.*+?^${}()|[\]\\]/g,"\\$&")}function C(e){var S,x=(e=e||{}).delimiter,O=e.newline,T=e.comments,I=e.step,D=e.preview,A=e.fastMode,L=S=void 0===e.quoteChar?'"':e.quoteChar;if(void 0!==e.escapeChar&&(L=e.escapeChar),("string"!=typeof x||-1<v.BAD_DELIMITERS.indexOf(x))&&(x=","),T===x)throw"Comment character same as delimiter";!0===T?T="#":("string"!=typeof T||-1<v.BAD_DELIMITERS.indexOf(T))&&(T=!1),"\n"!==O&&"\r"!==O&&"\r\n"!==O&&(O="\n");var P=0,F=!1;this.parse=function(r,t,i){if("string"!=typeof r)throw"Input must be a string";var n=r.length,e=x.length,s=O.length,a=T.length,o=M(I),h=[],u=[],f=[],d=P=0;if(!r)return E();if(A||!1!==A&&-1===r.indexOf(S)){for(var l=r.split(O),c=0;c<l.length;c++){if(f=l[c],P+=f.length,c!==l.length-1)P+=O.length;else if(i)return E();if(!T||f.substr(0,a)!==T){if(o){if(h=[],k(f.split(x)),R(),F)return E()}else k(f.split(x));if(D&&D<=c)return h=h.slice(0,D),E(!0)}}return E()}for(var p,_=r.indexOf(x,P),m=r.indexOf(O,P),g=new RegExp(L.replace(/[-[\]/{}()*+?.\\^$|]/g,"\\$&")+S,"g");;)if(r[P]!==S)if(T&&0===f.length&&r.substr(P,a)===T){if(-1===m)return E();P=m+s,m=r.indexOf(O,P),_=r.indexOf(x,P)}else if(-1!==_&&(_<m||-1===m))f.push(r.substring(P,_)),P=_+e,_=r.indexOf(x,P);else{if(-1===m)break;if(f.push(r.substring(P,m)),w(m+s),o&&(R(),F))return E();if(D&&h.length>=D)return E(!0)}else for(p=P,P++;;){if(-1===(p=r.indexOf(S,p+1)))return i||u.push({type:"Quotes",code:"MissingQuotes",message:"Quoted field unterminated",row:h.length,index:P}),b();if(p===n-1)return b(r.substring(P,p).replace(g,S));if(S!==L||r[p+1]!==L){if(S===L||0===p||r[p-1]!==L){var y=C(-1===m?_:Math.min(_,m));if(r[p+1+y]===x){f.push(r.substring(P,p).replace(g,S)),P=p+1+y+e,_=r.indexOf(x,P),m=r.indexOf(O,P);break}var v=C(m);if(r.substr(p+1+v,s)===O){if(f.push(r.substring(P,p).replace(g,S)),w(p+1+v+s),_=r.indexOf(x,P),o&&(R(),F))return E();if(D&&h.length>=D)return E(!0);break}u.push({type:"Quotes",code:"InvalidQuotes",message:"Trailing quote on quoted field is malformed",row:h.length,index:P}),p++}}else p++}return b();function k(e){h.push(e),d=P}function C(e){var t=0;if(-1!==e){var i=r.substring(p+1,e);i&&""===i.trim()&&(t=i.length)}return t}function b(e){return i||(void 0===e&&(e=r.substr(P)),f.push(e),P=n,k(f),o&&R()),E()}function w(e){P=e,k(f),f=[],m=r.indexOf(O,P)}function E(e){return{data:h,errors:u,meta:{delimiter:x,linebreak:O,aborted:F,truncated:!!e,cursor:d+(t||0)}}}function R(){I(E()),h=[],u=[]}},this.abort=function(){F=!0},this.getCharIndex=function(){return P}}function y(e){var t=e.data,i=h[t.workerId],r=!1;if(t.error)i.userError(t.error,t.file);else if(t.results&&t.results.data){var n={abort:function(){r=!0,b(t.workerId,{data:[],errors:[],meta:{aborted:!0}})},pause:w,resume:w};if(M(i.userStep)){for(var s=0;s<t.results.data.length&&(i.userStep({data:[t.results.data[s]],errors:t.results.errors,meta:t.results.meta},n),!r);s++);delete t.results}else M(i.userChunk)&&(i.userChunk(t.results,n,t.file),delete t.results)}t.finished&&!r&&b(t.workerId,t.results)}function b(e,t){var i=h[e];M(i.userComplete)&&i.userComplete(t),i.terminate(),delete h[e]}function w(){throw"Not implemented."}function E(e){if("object"!=typeof e||null===e)return e;var t=Array.isArray(e)?[]:{};for(var i in e)t[i]=E(e[i]);return t}function R(e,t){return function(){e.apply(t,arguments)}}function M(e){return"function"==typeof e}return o?f.onmessage=function(e){var t=e.data;void 0===v.WORKER_ID&&t&&(v.WORKER_ID=t.workerId);if("string"==typeof t.input)f.postMessage({workerId:v.WORKER_ID,results:v.parse(t.input,t.config),finished:!0});else if(f.File&&t.input instanceof File||t.input instanceof Object){var i=v.parse(t.input,t.config);i&&f.postMessage({workerId:v.WORKER_ID,results:i,finished:!0})}}:v.WORKERS_SUPPORTED&&(e=document.getElementsByTagName("script"),s=e.length?e[e.length-1].src:"",document.body?document.addEventListener("DOMContentLoaded",function(){a=!0},!0):a=!0),(c.prototype=Object.create(l.prototype)).constructor=c,(p.prototype=Object.create(l.prototype)).constructor=p,(_.prototype=Object.create(_.prototype)).constructor=_,(m.prototype=Object.create(l.prototype)).constructor=m,(g.prototype=Object.create(l.prototype)).constructor=g,v});
(function ($){

    $(document).ready(function() {
        function Parse() {
        }

        Parse.prototype.getSeparator = function(){
            let checked = ":";
            let checkedVal = "#separator_type";

            if ($(checkedVal).is(":checked")){
                console.log(checkedVal);
                checked = "|";
            }

            return checked;
        };

        Parse.prototype.handleLogic = function () {
            let csvString = $("#csv-string");
            let config = {
                delimiter: "",	// auto-detect
                newline: "",	// auto-detect
                quoteChar: '"',
                escapeChar: '"',
                header: false,
                trimHeaders: false,
                dynamicTyping: false,
                preview: 0,
                encoding: "",
                worker: false,
                comments: false,
                step: undefined,
                complete: undefined,
                error: undefined,
                download: false,
                skipEmptyLines: false,
                chunk: undefined,
                fastMode: undefined,
                beforeFirstChunk: undefined,
                withCredentials: undefined,
                transform: undefined
            };

            var $this = this;

            $("#submit-csv").click(function () {


                let parsedArr = [];
                let data = Papa.parse(csvString.val(), config);
                let row = data.data;

                for (let i = 0; i < row.length; i++) {

                    let formattedRow = row[i].slice(0, 2);
                    let strRow = formattedRow.toString();

                    parsedArr.push(strRow.replace(",", $this.getSeparator()));
                }

                $("#parse-results").text(parsedArr.toString().split(',').join("\n"));

            });
        };


        Parse.prototype.copyResult = function (element) {
            $(".copy-text").on('click', function () {
                let $temp = $("<textarea>");
                let brRegex = /<br\s*[\/]?>/gi;
                $("body").append($temp);
                $temp.val($(element).html().replace(brRegex, "\r\n")).select();
                document.execCommand("copy");
                $temp.remove();
                $(element).addClass("hightlight");
                $(element).select();

                $(".copied").addClass("active");
                setTimeout(function () {
                    $(".copied").removeClass('active');
                }, 2500);
            });

        };

        Parse.prototype.handleFocusOut = function (element) {
            $(element).focusout(function () {
                $(element).removeClass("hightlight");
            });
        };

        Parse.prototype.displayNotification = function (element, cssClass) {
            $(element).fadeIn("slow", function () {
                $(this).addClass("active");
            });
        };

        let parse = new Parse();
        let copyText = $("#parse-results");
        parse.handleLogic();
        parse.copyResult(copyText);
        parse.handleFocusOut(copyText);
    });


})(jQuery);