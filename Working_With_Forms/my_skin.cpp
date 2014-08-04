#line 1 "message.tmpl"
#include "content.h" 
#line 2 "message.tmpl"
namespace my_skin {
	#line 3 "message.tmpl"
	struct message :public cppcms::base_view
	#line 3 "message.tmpl"
	{
	#line 3 "message.tmpl"
		content::message &content;
	#line 3 "message.tmpl"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content)
	#line 3 "message.tmpl"
		{
	#line 3 "message.tmpl"
		}
		#line 4 "message.tmpl"
		virtual void render() {
			#line 7 "message.tmpl"
			out()<<"\n"
				"<html>\n"
				"    <body>\n"
				"        ";
			#line 7 "message.tmpl"
			if(!(content.name.empty())) {
				#line 8 "message.tmpl"
				out()<<"\n"
					"            <h1>Hello ";
				#line 8 "message.tmpl"
				out()<<cppcms::filters::escape(content.name);
				#line 9 "message.tmpl"
				out()<<"</h1>\n"
					"            <p>You are ";
				#line 9 "message.tmpl"
				out()<<cppcms::filters::escape(content.sex);
				#line 9 "message.tmpl"
				out()<<", ";
				#line 9 "message.tmpl"
				out()<<cppcms::filters::escape(content.state);
				#line 10 "message.tmpl"
				out()<<"</p>\n"
					"            <p>Your age is ";
				#line 10 "message.tmpl"
				out()<<cppcms::filters::escape(content.age);
				#line 11 "message.tmpl"
				out()<<"</p>\n"
					"        ";
			#line 11 "message.tmpl"
			}else{
				#line 13 "message.tmpl"
				out()<<"\n"
					"            <h1>Input your details</h1>\n"
					"        ";
			#line 13 "message.tmpl"
			}
			#line 14 "message.tmpl"
			out()<<"\n"
				"        <form method=\"post\" action=\"\">";
			#line 14 "message.tmpl"
			out() << "<input type=\"hidden\" name=\"_csrf\" value=\"" << content.app().session().get_csrf_token() <<"\" >\n";
			#line 15 "message.tmpl"
			out()<<"\n"
				"        ";
			#line 15 "message.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_p); (content.info).render(_form_context); }
			#line 19 "message.tmpl"
			out()<<"\n"
				"        </form>\n"
				"    </body>\n"
				"</html>\n"
				"";
		#line 19 "message.tmpl"
		} // end of template render
	#line 20 "message.tmpl"
	}; // end of class message
#line 21 "message.tmpl"
} // end of namespace my_skin
#line 21 "message.tmpl"
namespace {
#line 21 "message.tmpl"
 cppcms::views::generator my_generator; 
#line 21 "message.tmpl"
 struct loader { 
#line 21 "message.tmpl"
  loader() { 
#line 21 "message.tmpl"
   my_generator.name("my_skin");
#line 21 "message.tmpl"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 21 "message.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 21 "message.tmpl"
 }
#line 21 "message.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 21 "message.tmpl"
} a_loader;
#line 21 "message.tmpl"
} // anon 
