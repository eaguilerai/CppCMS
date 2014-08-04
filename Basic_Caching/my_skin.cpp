#line 1 "message.tmpl"
#include "content.h" 
#line 2 "message.tmpl"
namespace my_skin {
	#line 3 "message.tmpl"
	struct Message :public cppcms::base_view
	#line 3 "message.tmpl"
	{
	#line 3 "message.tmpl"
		content::Message &content;
	#line 3 "message.tmpl"
		Message(std::ostream &_s,content::Message &_content): cppcms::base_view(_s),content(_content)
	#line 3 "message.tmpl"
		{
	#line 3 "message.tmpl"
		}
		#line 4 "message.tmpl"
		virtual void render() {
			#line 8 "message.tmpl"
			out()<<"\n"
				"<html>\n"
				"    <body>\n"
				"        <h1>Factorial calculator</h1>\n"
				"        <h2>";
			#line 8 "message.tmpl"
			out()<<cppcms::filters::escape(content.arg);
			#line 8 "message.tmpl"
			out()<<"! = ";
			#line 8 "message.tmpl"
			out()<<cppcms::filters::escape(content.fact);
			#line 10 "message.tmpl"
			out()<<"</h2>\n"
				"        <form method=\"post\" action=\"\" >\n"
				"        ";
			#line 10 "message.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.info).render(_form_context); }
			#line 14 "message.tmpl"
			out()<<"\n"
				"        </form>\n"
				"    </body>\n"
				"</html>\n"
				"";
		#line 14 "message.tmpl"
		} // end of template render
	#line 15 "message.tmpl"
	}; // end of class Message
#line 16 "message.tmpl"
} // end of namespace my_skin
#line 16 "message.tmpl"
namespace {
#line 16 "message.tmpl"
 cppcms::views::generator my_generator; 
#line 16 "message.tmpl"
 struct loader { 
#line 16 "message.tmpl"
  loader() { 
#line 16 "message.tmpl"
   my_generator.name("my_skin");
#line 16 "message.tmpl"
   my_generator.add_view<my_skin::Message,content::Message>("Message",true);
#line 16 "message.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 16 "message.tmpl"
 }
#line 16 "message.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 16 "message.tmpl"
} a_loader;
#line 16 "message.tmpl"
} // anon 
