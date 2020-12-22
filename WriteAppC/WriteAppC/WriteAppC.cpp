#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main()
{
	ofstream fout;
	fout.open("MAP.txt", ios_base::trunc); // ios_base::trunc - если файл существует, то удаляем содержимое
	if (!fout.is_open())
		cout << "Fail" << endl;
	else
		cout << "ok!" << endl;
	cout << "Walls n: ";
	int n = 0;
	cin >> n;
	cout << endl;
	for (int i = 1; i < n + 1; i++)
	{
		fout << "$(document).on('click tap vclick', '#slide-" << i
		cout << endl;
	}
	fout.close();
	return 0;
}

// 3 slide
$(document).on("click tap vclick", "#slide-3_choose-1", function() {
	$("#slide-3_choose-1").removeClass('img-active');
	$("#slide-3_choose-2").addClass('img-active');
	$("#slide-3_choose-3").addClass('img-active');
	$("#slide-3_choose-4").addClass('img-active');
	$('#next3').prop('disabled', false);
	results[3] = $("#slide-3_choose-1").text();
});
$("#slide-3_choose-2").click(function() {
	$("#slide-3_choose-2").removeClass('img-active');
	$("#slide-3_choose-1").addClass('img-active');
	$("#slide-3_choose-3").addClass('img-active');
	$("#slide-3_choose-4").addClass('img-active');
	$('#next3').prop('disabled', false);
	results[3] = $("#slide-3_choose-2").text();
});
$("#slide-3_choose-3").click(function() {
	$("#slide-3_choose-3").removeClass('img-active');
	$("#slide-3_choose-2").addClass('img-active');
	$("#slide-3_choose-1").addClass('img-active');
	$("#slide-3_choose-4").addClass('img-active');
	$('#next3').prop('disabled', false);
	results[3] = $("#slide-1_choose-3").text();
});
$("#slide-3_choose-4").click(function() {
	$("#slide-3_choose-4").removeClass('img-active');
	$("#slide-3_choose-2").addClass('img-active');
	$("#cslide-3_choose-3").addClass('img-active');
	$("#slide-3_choose-1").addClass('img-active');
	$('#next3').prop('disabled', false);
	results[3] = $("#slide-3_choose-4").text();
});