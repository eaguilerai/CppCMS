#line 1 "content.tmpl"
#include "content.h" 
#line 2 "content.tmpl"
namespace skin {
	#line 3 "content.tmpl"
	struct Content :public cppcms::base_view
	#line 3 "content.tmpl"
	{
	#line 3 "content.tmpl"
		content::Content &content;
	#line 3 "content.tmpl"
		Content(std::ostream &_s,content::Content &_content): cppcms::base_view(_s),content(_content)
	#line 3 "content.tmpl"
		{
	#line 3 "content.tmpl"
		}
		#line 4 "content.tmpl"
		virtual void render() {
			#line 13 "content.tmpl"
			out()<<"\n"
				"<html>\n"
				"    <head>\n"
				"        <title>App</title>\n"
				"    </head>\n"
				"    <body>\n"
				"        <p>CppCMS starting application.</p>\n"
				"    </body>\n"
				"</html>\n"
				"";
		#line 13 "content.tmpl"
		} // end of template render
	#line 14 "content.tmpl"
	}; // end of class Content
#line 15 "content.tmpl"
} // end of namespace skin
#line 15 "content.tmpl"
namespace {
#line 15 "content.tmpl"
 cppcms::views::generator my_generator; 
#line 15 "content.tmpl"
 struct loader { 
#line 15 "content.tmpl"
  loader() { 
#line 15 "content.tmpl"
   my_generator.name("skin");
#line 15 "content.tmpl"
   my_generator.add_view<skin::Content,content::Content>("Content",true);
#line 15 "content.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 15 "content.tmpl"
 }
#line 15 "content.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 15 "content.tmpl"
} a_loader;
#line 15 "content.tmpl"
} // anon 
