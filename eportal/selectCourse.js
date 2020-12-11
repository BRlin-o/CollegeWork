function sleep(ms){

var starttime= new Date().getTime();

do{

}while((new Date().getTime()-starttime)<ms)

}


function mySelect(cid, loop_t, sleep_t){
    var param = { ccid: cid, op:'add', token:'b30c9542-3cfe-41e3-bb0c-182459e58663', type: 'pre_sel' };
	var data={strParam:"{}"};
	var obj = param;
	   // force to string type
	for (var key in obj)
		obj[key] = '' + obj[key];
	ajax_url = "/student/WebService.asmx/stuClassMod";
	data.strParam = JSON.encode(param);

	var msg;
	for(i=0;i<loop_t;++i){
		$.ajax({
			'async': false,
			'type': "POST",
			"contentType": "application/json; charset=utf-8",
			'cache': false,
			'url': ajax_url,
			'data': JSON.encode(data),
			'success': function(s) {
				msg = JSON.decode(s.d);
				console.log(msg[0].args);
			},
			'error': function (e) {
				console.log(e.responseText);
			}
		});
		sleep(sleep_t);
	}
}

mySelect(5846, 100000000, 500)