/* binding to gatsby link
   Running into default issue again. Name the bs module inside brackets and get default
   version of the module
   */
module Link = {
  [@bs.module "gatsby-link"]
  external linkClass : ReasonReact.reactClass = "default";
  let make =
      (
        ~to_: string,
        ~className: option(string)=?,
        ~activeStyle: option(Js.t({..}))=?,
        ~activeClassName: option(string)=?,
        children,
      ) => {
    /*
        React is complaining if activeStyle & activeClassName are translated
        to e.g. activeClassName=undefined inside a JSX tag
     */
    let props =
      {"to": to_, "className": Js.Nullable.fromOption(className)}
      |> (
        p =>
          switch (activeStyle) {
          | Some(v) => Js.Obj.assign(p, {"activeStyle": v})
          | None => p
          }
      )
      |> (
        p =>
          switch (activeClassName) {
          | Some(v) => Js.Obj.assign(p, {"activeClassName": v})
          | None => p
          }
      );
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, children);
  };
};

module ParallaxScroll = {
  [@bs.module "./components/ParallaxScroll"]
  external linkClass : ReasonReact.reactClass = "ParallaxScroll";
  let make = (~from: string, ~to_: string, ~props: Js.t({..}), children) => {
    let props = {"from": from, "to": to_, "props": props};
    ReasonReact.wrapJsForReason(~reactClass=linkClass, ~props, children);
  };
};

module Helmet = {
  [@bs.module "react-helmet"]
  external linkClass : ReasonReact.reactClass = "default";
  /* linkClass expects a meta property which we type as object as a record
     `* @param {Array} meta: [{"name": "description", "content": "Test description"}]`
     */
  type metaT =
    option(
      array(
        {
          .
          "name": string,
          "content": string,
        },
      ),
    );
  let make = (~title: option(string)=?, ~meta: metaT=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=linkClass,
      ~props={
        "title": Js.Nullable.fromOption(title),
        "meta": Js.Nullable.fromOption(meta),
      },
      children,
    );
};