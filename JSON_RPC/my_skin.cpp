#line 1 "client.tmpl"
#include "content.h" 
#line 2 "client.tmpl"
namespace skin {
	#line 3 "client.tmpl"
	struct Client :public cppcms::base_view
	#line 3 "client.tmpl"
	{
	#line 3 "client.tmpl"
		content::None &content;
	#line 3 "client.tmpl"
		Client(std::ostream &_s,content::None &_content): cppcms::base_view(_s),content(_content)
	#line 3 "client.tmpl"
		{
	#line 3 "client.tmpl"
		}
		#line 4 "client.tmpl"
		virtual void render() {
			#line 58 "client.tmpl"
			out()<<"\n"
				"<html>\n"
				"    <head>\n"
				"        <script>\n"
				"            function call() {\n"
				"                var xhr = new XMLHttpRequest();\n"
				"                xhr.open(\"post\", \"/rpc\", true);\n"
				"                // Required by JSON-RPC over HTTP\n"
				"                xhr.setRequestHeader(\"Content-Type\", \"application/json\");\n"
				"\n"
				"                // It is better to use real formatter like JSON.js\n"
				"                var x = parseInt(document.getElementById(\"x\"));\n"
				"                var y = parseInt(document.getElementById(\"y\"));\n"
				"                //var request = '{\"method\" : \"div\", \"params\" : '\n"
				"                //    + '[' + x + ',' + y + '], \"id\" : 1}';\n"
				"                var request = '{\"method\":\"div\",\"params\":[' + x + ',' + y +'],\"id\":1}';\n"
				"\n"
				"                xhr.onreadystatechange = function() {\n"
				"                    if (xhr.readyState === 4) {\n"
				"                        var res;\n"
				"                        \n"
				"                        if (xhr.status === 200) {\n"
				"                            // Don't call eval in real code. Use some parser.\n"
				"                            var result = eval(\"(\" + xhr.responseText + \")\");\n"
				"\n"
				"                            if (result.error == null) {\n"
				"                                res = result.result;\n"
				"                            }\n"
				"                            else {\n"
				"                                res = result.error;\n"
				"                            }\n"
				"                        }\n"
				"                        else {\n"
				"                            res = \"Invalid Status \" + xhr.status;\n"
				"                        }\n"
				"\n"
				"                        document.getElementById(\"result\").innerHTML = res;\n"
				"                    }\n"
				"                }\n"
				"\n"
				"                xhr.send(request);\n"
				"                return false;\n"
				"            }\n"
				"        </script>\n"
				"    </head>\n"
				"    <body>\n"
				"        <form onsubmit=\"return call();\">\n"
				"            <input id=\"x\" type=\"text\" />\n"
				"            <button type=\"submit\">/</button>\n"
				"            <input id=\"y\" type=\"text\" /> = \n"
				"            <span id=\"result\"></span>\n"
				"        </form>\n"
				"    </body>\n"
				"</html>\n"
				"";
		#line 58 "client.tmpl"
		} // end of template render
	#line 59 "client.tmpl"
	}; // end of class Client
#line 60 "client.tmpl"
} // end of namespace skin
#line 61 "client.tmpl"
namespace {
#line 61 "client.tmpl"
 cppcms::views::generator my_generator; 
#line 61 "client.tmpl"
 struct loader { 
#line 61 "client.tmpl"
  loader() { 
#line 61 "client.tmpl"
   my_generator.name("skin");
#line 61 "client.tmpl"
   my_generator.add_view<skin::Client,content::None>("Client",true);
#line 61 "client.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 61 "client.tmpl"
 }
#line 61 "client.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 61 "client.tmpl"
} a_loader;
#line 61 "client.tmpl"
} // anon 
