import { Popover, Transition } from "@headlessui/react";
import { QuestionMarkCircleIcon, XIcon } from "@heroicons/react/outline";
import { Fragment } from "react";

export default function InfoPopup() {
  return (
    <Popover>
      <Popover.Button className="flex items-center justify-center">
        <QuestionMarkCircleIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
      </Popover.Button>
      <Transition
        as={Fragment}
        enter="transform transition ease-in duration-100"
        enterFrom="opacity-0"
        enterTo="opacity-100"
        leave="transform transition ease-in duration-100"
        leaveFrom="opacity-100"
        leaveTo="opacity-0"
      >
        <Popover.Panel className="fixed flex flex-col items-center justify-center gap-4 p-4 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl top-20 left-4 right-4 md:w-3/12">
          <div className="flex justify-between w-full itemns-center">
            <h2 className="text-base font-semibold text-gray-200 md:text-lg lg:text-xl">
              Comment jouer ?
            </h2>
            <Popover.Button>
              <XIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
            </Popover.Button>
          </div>
          <div className="w-full border-t-2 border-gray-600"></div>
          <p className="text-base text-gray-200 md:text-lg lg:text-xl">
            Lorem ipsum dolor, sit amet consectetur adipisicing elit. Sequi
            optio in tempore aliquam earum quibusdam omnis ipsum!
          </p>
        </Popover.Panel>
      </Transition>
    </Popover>
  );
}
