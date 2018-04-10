%raw
"require('normalize.css')";

%raw
"require('./index.scss')";

/* convert to using Helmut in Reason via Gatsby.re */
module Helmet = Gatsby.Helmet;

/* reason version of templatewrapper component */
let component = ReasonReact.statelessComponent("TemplateWrapper");

let title = "Linstaver";

let make = (~location, children) => {
  ...component,
  render: _self => {
    let isHomepage = location##pathname == "/";
    /* check if on thanks page, if so dont render */
    /* let isThanksPage = location##pathname == "/thanks/"; */
    <div className="page">
      <Helmet title />
      (
        if (isHomepage) {
          <main> (children()) </main>;
        } else {
          <div className="container container_centered">
            <header> <Navigation pathName=location##pathname /> </header>
            <article> (children()) </article>
          </div>;
        }
      )
      <Footer />
    </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~location=jsProps##location, jsProps##children)
  );