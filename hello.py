from sanic import Sanic
from sanic.response import json

app = Sanic(__name__)

#@app.route("/")
#async def test(request):
#	return json({ "hello": "world" })

@app.route("/", methods=["POST",])
def query_string(request):
	print("got client")
	print(request.query_string)
	return json({ "parsed": True, "args": request.args, "url": request.url, "query_string": request.query_string })

app.run(host="127.0.0.1", port=8000, debug=True)
